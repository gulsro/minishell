#include "../../include/minishell.h"

/*
**	is_builtin() checks if given command is a built-in command
*/
int is_builtin(t_command *command)
{
	return (ft_strsame(command->args[0], "cd") == 1
			|| ft_strsame(command->args[0], "echo") == 1
			|| ft_strsame(command->args[0], "pwd") == 1
			|| ft_strsame(command->args[0], "env") == 1
			|| ft_strsame(command->args[0], "exit") == 1
			|| ft_strsame(command->args[0], "export") == 1
			|| ft_strsame(command->args[0], "unset") == 1);
}

/*
**	simple_command_exec() handles execution of a single command without pipe.
*/
void execute_simple_command(t_tools *tools)
{
	t_command *command;
	pid_t p1;
	
	command = tools->command_list;
	p1 = fork();
	if (p1 == -1)
		error_exit("fork failed", 1);
	else if (p1 == 0)
	{
		redirection(command);
		execute_child(tools);
	}
}

void execute(t_tools *tools)
{
	t_command *command_list;

	command->list = tools->command_list;
	if (tools->number_of_pipes == 1)
	{
		if (is_builtin(command_list) == 1)
			choose_builtin(tools);
		else
			execute_simple_command(command_list);
	}
	else
	{
		printf("here pipes need to be execute()\n");
		return ;
	}
}