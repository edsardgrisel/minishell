/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egrisel <egrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:44:11 by egrisel           #+#    #+#             */
/*   Updated: 2025/09/10 14:32:44 by egrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <stdio.h>

int	main()
{
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║            TEST TOKENIZE             ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\n");
    test_tokenize();
    
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║          TEST PARSE COMMAND          ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\n");
    test_parse_command();
    
	printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║           TEST PARSE EXECUTABLE      ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\n");
    test_parse_executable();

    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║         TEST PARSE PIPELINE          ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\n");
    test_parse_pipeline();
    
    printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║           TEST CREATE AST            ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\n");
    test_create_ast();

	printf("\n");
    printf("╔══════════════════════════════════════╗\n");
    printf("║           TEST BUILTINS              ║\n");
    printf("╚══════════════════════════════════════╝\n");
    printf("\n");
    test_builtins();
}