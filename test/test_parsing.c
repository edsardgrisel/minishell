/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:28:54 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/08 16:44:35 by egrisel          ###   ########.fr       */
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
        case NODE_COMMAND:
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
    if (node->command_and_args)
    {
        printf("command_and_args: [");
		printf("\"%s\"", node->command_and_args);
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
    printf("Test 3: ls | wc | grep 1\n\n");
    i = 0;
    t_ast_node *ast3 = parse_pipeline(tokens3, &i);
    print_ast(ast3);

	t_ast_node	*left = ast3->left;
	t_ast_node	*right = ast3->right;
	t_ast_node	*left_left = ast3->left->left;
	t_ast_node	*left_right = ast3->left->right;



	assert(left->node_type == NODE_PIPE);
	assert(right->node_type == NODE_COMMAND && strcmp(right->command_and_args, "grep 1") == 0);
	assert(left_left->node_type == NODE_COMMAND && strcmp(left_left->command_and_args, "ls") == 0);
	assert(left_right->node_type == NODE_COMMAND && strcmp(left_right->command_and_args, "wc") == 0);


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
	assert(right->node_type == NODE_COMMAND && strcmp(right->command_and_args, "grep 1") == 0);
	assert(left_left->node_type == NODE_COMMAND && strcmp(left_left->command_and_args, "ls") == 0);
	assert(left_right->node_type == NODE_COMMAND && strcmp(left_right->command_and_args, "wc") == 0);
	printf("%i %s passed!\n\n", i++, line1);


	//////////////////////////
	// // Test 2
	///////////////////////////
	char	*line2 = "ls > out.txt";
	t_ast_node *ast2 = create_ast(line2);
	t_ast_node	*left2 = ast2->left;
	assert(ast2->node_type == NODE_REDIRECT_OUT && strcmp(ast2->redirect_file, "out.txt") == 0);
	assert(left2->node_type == NODE_COMMAND && strcmp(left2->command_and_args, "ls") == 0);
	printf("%i %s passed!\n\n", i++, line2);

	//////////////////////////
	// // Test 3
	///////////////////////////
	// char	*line3 = "ls |";
	// t_ast_node *ast3 = create_ast(line3);
	// t_ast_node	*left3 = ast2->left;
	// assert(ast3->node_type == NODE_PIPE);
	// assert(left3->node_type == NODE_COMMAND && str);

	// printf("%i %s passed!\n\n", i++, line3);



	char	*line4 = "/bin/echo hi >./outfiles/outfile01 | /bin/echo bye";
	t_ast_node *ast4 = create_ast(line4);
	t_ast_node	*left4 = ast4->left;
	t_ast_node	*left_left4 = ast4->left->left;
	t_ast_node	*right4 = ast4->right;

	assert(ast4->node_type == NODE_PIPE);
	assert(left4->node_type == NODE_REDIRECT_OUT && strcmp(left4->redirect_file, "./outfiles/outfile01") == 0);
	assert(left_left4->node_type == NODE_COMMAND && strcmp(left_left4->command_and_args, "/bin/echo hi") == 0);
	assert(right4->node_type == NODE_COMMAND && strcmp(right4->command_and_args, "/bin/echo bye") == 0);



	printf("%i %s passed!\n\n", i++, line2);
}
