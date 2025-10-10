/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:44:50 by egrisel           #+#    #+#             */
/*   Updated: 2025/10/10 13:31:23 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

// Color codes
# define COLOR_RESET    "\033[0m"
# define COLOR_RED      "\033[1;31m"
# define COLOR_GREEN    "\033[1;32m"
# define COLOR_YELLOW   "\033[1;33m"
# define COLOR_BLUE     "\033[1;34m"
# define COLOR_MAGENTA  "\033[1;35m"
# define COLOR_CYAN     "\033[1;36m"
# define COLOR_WHITE    "\033[1;37m"

// Test status
# define TEST_PASS      COLOR_GREEN "✅ PASSED" COLOR_RESET
# define TEST_FAIL      COLOR_RED "❌ FAILED" COLOR_RESET

#include "minishell.h"

void	test_tokenize();
void	test_parse_command();
void test_parse_executable();
void	test_parse_pipeline();
void	test_create_ast();
void	test_builtins();


t_ast_node	*create_ast(char *line);
