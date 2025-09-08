/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:39:38 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/08 16:03:40 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "test.h"
#include "minishell.h"
#include <string.h>
#include <stdio.h>

static int token_equals(t_token *tokens_got, t_token *tokens_exp)
{
	int i = 0;

	while (tokens_got[i].type != TOKEN_NONE && tokens_exp[i].type != TOKEN_NONE)
	{
		if (tokens_got[i].type == TOKEN_WORD && strcmp(tokens_got[i].value, tokens_exp[i].value) != 0)
		{
			printf("Got: %s\nExp: %s\n", tokens_got[i].value, tokens_exp[i].value);
			return 0;
		}
		if (tokens_got[i].type != tokens_exp[i].type)
		{
			printf("Got %s (type: %d)\nExp %s (type: %d)\n", tokens_got[i].value, tokens_got[i].type, tokens_exp[i].value, tokens_exp[i].type);
			return 0;
		}
		i++;
	}
	if (tokens_got[i].type == TOKEN_NONE && tokens_exp[i].type == TOKEN_NONE)
		return (1);
	printf("Token List of different length\n");
	return (0);
}

static void	test_tokenize_helper(char *line, t_token *tokens_exp)
{
	t_token	*tokenize_result = tokenize(line);
	if (token_equals(tokenize_result, tokens_exp) == 0)
		printf(TEST_FAIL "\n");
	else
		printf(TEST_PASS "\n");
	for (int i = 0; tokenize_result[i].type != TOKEN_NONE; i++)
	{
		if (tokenize_result[i].type == TOKEN_WORD)
			free(tokenize_result[i].value);
	}
	free(tokenize_result);
}


static void	test_tokenize1(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[5] = {
		{TOKEN_WORD, "ls"},
		{TOKEN_PIPE, "|"},
		{TOKEN_WORD, "grep"},
		{TOKEN_WORD, "a"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("ls | grep a", tokens_exp);
}

static void	test_tokenize2(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[3] = {
		{TOKEN_WORD, "echo"},
		{TOKEN_WORD, "hello"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("echo hello", tokens_exp);
}

static void	test_tokenize3(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[2] = {
		{TOKEN_WORD, "ls"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("ls", tokens_exp);
}

static void	test_tokenize4(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[8] = {
		{TOKEN_WORD, "ps"},
		{TOKEN_WORD, "aux"},
		{TOKEN_PIPE, "|"},
		{TOKEN_WORD, "grep"},
		{TOKEN_WORD, "bash"},
		{TOKEN_PIPE, "|"},
		{TOKEN_WORD, "wc"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("ps aux | grep bash | wc", tokens_exp);
}

static void	test_tokenize5(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[3] = {
		{TOKEN_WORD, "echo"},
		{TOKEN_WORD, "\"hello 	world\""},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("echo \"hello 	world\"", tokens_exp);
	test_tokenize_helper("echo	\"hello 	world\"    ", tokens_exp);

}

static void	test_tokenize6(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[4] = {
		{TOKEN_WORD, "cat"},
		{TOKEN_REDIRECT_HEREDOC, NULL},
		{TOKEN_WORD, "a"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("cat << a", tokens_exp);
}

static void	test_tokenize7(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[4] = {
		{TOKEN_WORD, "cat"},
		{TOKEN_REDIRECT_APPEND, NULL},
		{TOKEN_WORD, "a"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("cat >> a", tokens_exp);
	test_tokenize_helper("cat>> a", tokens_exp);
	test_tokenize_helper("cat >>a", tokens_exp);
	test_tokenize_helper("cat>>a", tokens_exp);
}

static void	test_tokenize8(void)
{
	printf("%s\n", __func__);

	t_token tokens_exp[11] = {
		{TOKEN_WORD, "ls"},
		{TOKEN_PIPE, "|"},
		{TOKEN_WORD, "grep"},
		{TOKEN_WORD, "a"},
		{TOKEN_PIPE, "|"},
		{TOKEN_WORD, "wc"},
		{TOKEN_WORD, "-l"},
		{TOKEN_PIPE, "|"},
		{TOKEN_REDIRECT_APPEND, ">>"},
		{TOKEN_WORD, "a.txt"},
		{TOKEN_NONE, NULL},
	};
	test_tokenize_helper("ls | grep a | wc -l | >> a.txt", tokens_exp);
	test_tokenize_helper("ls|grep a|wc -l|>>a.txt", tokens_exp);
	test_tokenize_helper("	ls 	|  grep      a|			wc -l |>>a.txt   ", tokens_exp);

}

// if type is not word, value doesnt matter.
void	test_tokenize()
{
	test_tokenize1();
	test_tokenize2();
	test_tokenize3();
	test_tokenize4();
	test_tokenize5();
	test_tokenize6();
	test_tokenize7();
	test_tokenize8();





	
}