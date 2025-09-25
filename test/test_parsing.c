/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:28:54 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/25 15:17:47 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "minishell.h"
#include <stdio.h>
#include <string.h>
#include "test.h"

void print_node_box(t_ast_node *node, int depth)
{
    if (!node)
    {
        printf("%*s[NULL]\n", depth * 4, "");
        return;
    }

    // Print indentation
    printf("%*s", depth * 4, "");
    
    // Top border
    printf("┌─────────────────────────┐\n");
    
    // Node type
    printf("%*s│ Type: ", depth * 4, "");
    switch (node->node_type)
    {
        case NODE_CMD:
            printf("COMMAND         \n");
            break;
        case NODE_PIPE:
            printf("PIPE            \n");
            break;
        case NODE_REDIRECT_IN:
            printf("REDIRECT_IN     \n");
            break;
        case NODE_REDIRECT_OUT:
            printf("REDIRECT_OUT    \n");
            break;
        case NODE_REDIRECT_APPEND:
            printf("REDIRECT_APPEND \n");
            break;
        case NODE_REDIRECT_HEREDOC:
            printf("REDIRECT_HEREDOC\n");
            break;
        default:
            printf("UNKNOWN         │\n");
    }
    

    
    // Args array (if exists)
    if (node->cmd_str)
    {
        printf("cmd_str: [");
		printf("\"%s\"", node->cmd_str);
        printf("]│\n");
    }
    else
    {
        printf("%*s│ Args[]: NULL          \n", depth * 4, "");
    }
    
    // File (if exists)
    if (node->redirect_file)
    {
        printf("%*s│ Redirect File: %-12s\n", depth * 4, "", node->redirect_file);
    }
    else
    {
        printf("%*s│ Redirect File: NULL           \n", depth * 4, "");
    }
    
    // Bottom border
    printf("%*s└─────────────────────────┘\n", depth * 4, "");
}

void print_ast_recursive(t_ast_node *node, int depth, const char *position)
{
    if (!node)
        return;
    
    // Print position indicator
    if (depth > 0)
    {
        printf("%*s%s\n", (depth - 1) * 4, "", position);
        printf("%*s│\n", (depth - 1) * 4, "");
    }
    
    // Print the node box
    print_node_box(node, depth);
    
    // Print children without connection lines
    if (node->left)
    {
        printf("%*sLEFT:\n", depth * 4, "");
        print_ast_recursive(node->left, depth + 1, "");
    }
    
    if (node->right)
    {
        printf("%*sRIGHT:\n", depth * 4, "");
        print_ast_recursive(node->right, depth + 1, "");
    }
}

void print_ast(t_ast_node *root)
{
    // printf("\n=== AST STRUCTURE ===\n");
    // if (!root)
    // {
    //     printf("AST is NULL\n");
    //     return;
    // }
    
    // print_ast_recursive(root, 0, "ROOT");
    // printf("=== END AST ===\n\n");
}

// Test function
void test_parse_command()
{
    printf("Testing parse_command with various inputs:\n\n");
    int	i;
	////////////////////////
    // Test 1: Simple command
	///////////////////////
    t_token tokens1[] = {
        {TOKEN_WORD, "ls"},
        {TOKEN_WORD, "-l"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 1: ls -l\n");
    i = 0;
    t_ast_node *ast1 = parse_command(tokens1, &i);
    print_ast(ast1);
	
	
    //////////////////////////////////
    // Test 2: Command with redirect
	//////////////////////////////////
    t_token tokens2[] = {
        {TOKEN_WORD, "cat"},
        {TOKEN_WORD, "file.txt"},
        {TOKEN_REDIRECT_OUT, ">"},
        {TOKEN_WORD, "output.txt"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 2: cat file.txt > output.txt\n");
    i = 0;
    t_ast_node *ast2 = parse_command(tokens2, &i);
    print_ast(ast2);
    
	
	/////////////////////////
    // Test 3: Mixed order
	/////////////////////////
    t_token tokens3[] = {
        {TOKEN_WORD, "cat"},
        {TOKEN_WORD, "1.txt"},
        {TOKEN_REDIRECT_OUT, ">"},
        {TOKEN_WORD, "out.txt"},
        {TOKEN_WORD, "2.txt"},
        {TOKEN_NONE, NULL}
    };
	i = 0;
    printf("Test 3: cat 1.txt > out.txt 2.txt\n");
	t_ast_node *ast3 = parse_command(tokens3, &i);
    print_ast(ast3);

	////////////////////////
	// Test 4: Multiple redirects
	/////////////////////////
    t_token tokens4[] = {
        {TOKEN_WORD, "cat"},
        {TOKEN_WORD, "1.txt"},
        {TOKEN_REDIRECT_OUT, ">"},
        {TOKEN_WORD, "out1.txt"},
        {TOKEN_REDIRECT_OUT, ">"},
        {TOKEN_WORD, "out2.txt"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 4: cat 1.txt > out1.txt > out2.txt\n\n");
    i = 0;
    t_ast_node *ast4 = parse_command(tokens4, &i);
    print_ast(ast4);



}

void test_parse_executable()
{
	int	i;
	////////////////////////
    // Test 1: Redirect out followed by command
	///////////////////////
    t_token tokens1[] = {
        {TOKEN_REDIRECT_OUT, ">"},
        {TOKEN_WORD, "out.txt"},
        {TOKEN_WORD, "ls"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 1: > out.txt ls\n");
    i = 0;
    t_ast_node *ast1 = parse_executable(tokens1, &i);
	assert(ast1->node_type == NODE_REDIRECT_OUT);
	assert(strcmp(ast1->redirect_file, "out.txt") == 0);
	assert(ast1->left->node_type == NODE_CMD);
	assert(strcmp(ast1->left->cmd_str, "ls") == 0);
	

	////////////////////////
    // Test 2: Heredoc
	///////////////////////
    t_token tokens2[] = {
        {TOKEN_REDIRECT_HEREDOC, NULL},
        {TOKEN_WORD, "abc"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 2: >> abc\n");
    i = 0;
    t_ast_node *ast2 = parse_executable(tokens2, &i);
	assert(ast2->node_type == NODE_REDIRECT_HEREDOC);
	assert(strcmp(ast2->heredoc_delim, "abc") == 0);
}

void	test_parse_pipeline()
{
	int	i;

	////////////////////////
	// Test 1: Basic single pipe
	/////////////////////////
    t_token tokens1[] = {
        {TOKEN_WORD, "ls"},
        {TOKEN_PIPE, NULL},
        {TOKEN_WORD, "wc"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 1: ls | wc\n\n");
    i = 0;
    t_ast_node *ast1 = parse_pipeline(tokens1, &i);
    print_ast(ast1);

	//////////////////////////
	// // Test 2: single pipe to redirect
	///////////////////////////
    t_token tokens2[] = {
        {TOKEN_WORD, "ls"},
        {TOKEN_WORD, "-l"},
		{TOKEN_PIPE, NULL},
        {TOKEN_WORD, "wc"},
        {TOKEN_REDIRECT_OUT, NULL},
        {TOKEN_WORD, "out.txt"},


        {TOKEN_NONE, NULL}
    };
    printf("Test 2: ls -l | wc > out.txt\n\n");
    i = 0;
    t_ast_node *ast2 = parse_pipeline(tokens2, &i);
    print_ast(ast2);


	
/*
				PIPE
				/    \
			PIPE      COMMAND
			/    \     ["grep 1"]
		COMMAND  COMMAND
		["ls"]   ["wc"]
 */
		//////////////////////////
	// // Test 3: double pipe
	///////////////////////////
    t_token tokens3[] = {
        {TOKEN_WORD, "ls"},
        {TOKEN_PIPE, NULL},
        {TOKEN_WORD, "wc"},
        {TOKEN_PIPE, NULL},
        {TOKEN_WORD, "grep"},
        {TOKEN_WORD, "1"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 3: ls > outfile wc | grep 1\n\n");
    i = 0;
    t_ast_node *ast3 = parse_pipeline(tokens3, &i);
    print_ast(ast3);

	t_ast_node	*left = ast3->left;
	t_ast_node	*right = ast3->right;
	t_ast_node	*left_left = ast3->left->left;
	t_ast_node	*left_right = ast3->left->right;

	assert(left->node_type == NODE_PIPE);
	assert(right->node_type == NODE_CMD && strcmp(right->cmd_str, "grep 1") == 0);
	assert(left_left->node_type == NODE_CMD && strcmp(left_left->cmd_str, "ls") == 0);
	assert(left_right->node_type == NODE_CMD && strcmp(left_right->cmd_str, "wc") == 0);



	//////////////////////////
	// // Test 4: export with many args
	///////////////////////////
    t_token tokens4[] = {
        {TOKEN_WORD, "export"},
        {TOKEN_WORD, "abc=hello"},
        {TOKEN_WORD, "last_name=john"},
        {TOKEN_NONE, NULL}
    };
    printf("Test 4: export abc=hello last_name=john\n\n");
    i = 0;
    t_ast_node *ast4 = parse_pipeline(tokens4, &i);
    

	t_arg_list	*first_arg4 = ast4->arg_list;
	t_arg_list	*second_arg4 = first_arg4->next;
	t_arg_list	*third_arg4 = second_arg4->next;



	assert(strcmp(first_arg4->str, "abc=hello") == 0);
	assert(strcmp(second_arg4->str, "last_name=john") == 0);
	assert(third_arg4 == NULL);

}


void	test_create_ast()
{
	int i = 1;
	//////////////////////////
	// // Test 1
	///////////////////////////
	/*
				PIPE
				/    \
			PIPE      COMMAND
			/    \     ["grep 1"]
		COMMAND  COMMAND
		["ls"]   ["wc"]
	*/
	char	*line1 = "ls | wc | grep 1";
	t_ast_node *ast1 = create_ast(line1);
	t_ast_node	*left = ast1->left;
	t_ast_node	*right = ast1->right;
	t_ast_node	*left_left = ast1->left->left;
	t_ast_node	*left_right = ast1->left->right;
	assert(ast1->node_type == NODE_PIPE);
	assert(left->node_type == NODE_PIPE);
	assert(right->node_type == NODE_CMD && strcmp(right->cmd_str, "grep 1") == 0);
	assert(left_left->node_type == NODE_CMD && strcmp(left_left->cmd_str, "ls") == 0);
	assert(left_right->node_type == NODE_CMD && strcmp(left_right->cmd_str, "wc") == 0);
	
	assert(strcmp(right->arg_list->str, "1") == 0);
	assert(right->arg_list->next == NULL);

	printf("%i %s passed!\n\n", i++, line1);


	//////////////////////////
	// // Test 2
	///////////////////////////
	char	*line2 = "ls > out.txt";
	t_ast_node *ast2 = create_ast(line2);
	t_ast_node	*left2 = ast2->left;
	assert(ast2->node_type == NODE_REDIRECT_OUT && strcmp(ast2->redirect_file, "out.txt") == 0);
	assert(left2->node_type == NODE_CMD && strcmp(left2->cmd_str, "ls") == 0);
	printf("%i %s passed!\n\n", i++, line2);

	//////////////////////////
	// // Test 3
	///////////////////////////
	// char	*line3 = "ls |";
	// t_ast_node *ast3 = create_ast(line3);
	// t_ast_node	*left3 = ast2->left;
	// assert(ast3->node_type == NODE_PIPE);
	// assert(left3->node_type == NODE_CMD && str);

	// printf("%i %s passed!\n\n", i++, line3);



	char	*line4 = "/bin/echo hi >./outfiles/outfile01 | /bin/echo bye";
	t_ast_node *ast4 = create_ast(line4);
	t_ast_node	*left4 = ast4->left;
	t_ast_node	*left_left4 = ast4->left->left;
	t_ast_node	*right4 = ast4->right;

	assert(ast4->node_type == NODE_PIPE);
	assert(left4->node_type == NODE_REDIRECT_OUT && strcmp(left4->redirect_file, "./outfiles/outfile01") == 0);
	assert(left_left4->node_type == NODE_CMD && strcmp(left_left4->cmd_str, "/bin/echo hi") == 0);
	assert(right4->node_type == NODE_CMD && strcmp(right4->cmd_str, "/bin/echo bye") == 0);



	printf("%i %s passed!\n\n", i++, line2);
}
