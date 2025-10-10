/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:44:11 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/10 14:54:22 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

void	test_new_parser()
{
	int	i;
	
	////////////////////////
	// Test 1: Single pipe
	///////////////////////
	t_token tokens1[] = {
		{TOKEN_WORD, "ls"},
		{TOKEN_WORD, "-l"},
		{TOKEN_PIPE, NULL},
		{TOKEN_WORD, "wc"},
		{TOKEN_NONE, NULL}
	};
	printf("Test 1: ls -l | wc\n");
	i = 0;
	t_ast_node *ast1 = parse_pipeline(tokens1, &i);
	assert(strcmp(ast1->cmd_list[0], "ls") == 0);
	assert(strcmp(ast1->cmd_list[1], "-l") == 0);
	assert(ast1->cmd_list[2 ]== NULL);
	assert(ast1->node_type == NODE_CMD);

	t_ast_node *ast2 = ast1->next;
	assert(strcmp(ast2->cmd_list[0], "wc") == 0);
	assert(ast2->cmd_list[1] == NULL);

	// 	////////////////////////
	// // Test 2: Double pipe redirect
	// ///////////////////////
	// t_token tokens2[] = {
	// 	{TOKEN_WORD, "ls"},
	// 	{TOKEN_PIPE, NULL},
	// 	{TOKEN_WORD, "wc"},
	// 	{TOKEN_PIPE, NULL},
	// 	{TOKEN_WORD, "grep 1"},
	// 	{TOKEN_REDIRECT_OUT, NULL},
	// 	{TOKEN_WORD, "out.txt"},
	// 	{TOKEN_NONE, NULL}
	// };
	// printf("Test 1: ls | wc | grep 1 > out.txt\n");
	// i = 0;
	// ast1 = parse_pipeline(tokens2, &i);
	
	// assert(strcmp(ast1->cmd_list[0], "ls") == 0);
	// assert(ast1->cmd_list[1]== NULL);
	// assert(ast1->node_type == NODE_CMD);

	// ast2 = ast1->next;
	// assert(strcmp(ast2->cmd_list[0], "wc") == 0);
	// assert(ast2->cmd_list[1] == NULL);

	// t_ast_node * ast3 = ast2->next;
	// assert(strcmp(ast3->cmd_list[0], "grep") == 0);
	// assert(strcmp(ast3->cmd_list[1], "1") == 0);
	// assert(ast3->node_type == NODE_REDIRECT_OUT);
	// assert(strcmp(ast3->redirect_file, "out.txt") == 0);



	// assert(ast3->cmd_list[1] == NULL);


}

int	main()
{

    test_new_parser();
	
	
    // printf("\n");
    // printf("╔══════════════════════════════════════╗\n");
    // printf("║            TEST TOKENIZE             ║\n");
    // printf("╚══════════════════════════════════════╝\n");
    // printf("\n");
    // test_tokenize();
    
    // printf("\n");
    // printf("╔══════════════════════════════════════╗\n");
    // printf("║          TEST PARSE COMMAND          ║\n");
    // printf("╚══════════════════════════════════════╝\n");
    // printf("\n");
    // test_parse_command();
    
	// printf("\n");
    // printf("╔══════════════════════════════════════╗\n");
    // printf("║           TEST PARSE EXECUTABLE      ║\n");
    // printf("╚══════════════════════════════════════╝\n");
    // printf("\n");
    // // test_parse_executable();

    // printf("\n");
    // printf("╔══════════════════════════════════════╗\n");
    // printf("║         TEST PARSE PIPELINE          ║\n");
    // printf("╚══════════════════════════════════════╝\n");
    // printf("\n");
    // // test_parse_pipeline();
    
    // printf("\n");
    // printf("╔══════════════════════════════════════╗\n");
    // printf("║           TEST CREATE AST            ║\n");
    // printf("╚══════════════════════════════════════╝\n");
    // printf("\n");
    // test_create_ast();

	// printf("\n");
    // printf("╔══════════════════════════════════════╗\n");
    // printf("║           TEST BUILTINS              ║\n");
    // printf("╚══════════════════════════════════════╝\n");
    // printf("\n");
    // test_builtins();
}