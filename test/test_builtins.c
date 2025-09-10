#include "minishell.h"
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void test_echo_helper(char *line, char *exp)
{
	t_ast_node *ast = create_ast(line);
	t_minishell_info	minishell_info;
	
	int pipefd[2];
	pipe(pipefd);
	
	pid_t pid = fork();
	if (pid == 0)
	{
		// Child process
		close(pipefd[0]);  // Close read end
		dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
		close(pipefd[1]);
		
		exec_echo(ast, &minishell_info);  // Your echo function
		exit(0);
	}
	else
	{
		// Parent process
		close(pipefd[1]);  // Close write end
		
		char buffer[1024] = {0};
		read(pipefd[0], buffer, sizeof(buffer) - 1);
		close(pipefd[0]);
		
		waitpid(pid, NULL, 0);
		
		// Test the output
		printf("Echo output: '%s'\n", buffer);
		printf("Exp output : '%s'\n", exp);
		assert(strcmp(buffer, exp) == 0);
		printf("✅ Echo test passed!\n");
	}
}



void	test_builtins()
{
	test_echo_helper("echo hello", "hello\n");
	test_echo_helper("echo -n hello", "hello");
	test_echo_helper("echo -nnnnn -n hello", "hello");
	test_echo_helper("echo -na hello", "-na hello\n");
	test_echo_helper("echo", "\n");




}