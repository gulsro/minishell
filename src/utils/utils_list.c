#include "../../include/minishell.h"

// t_command	*ft_lstnew_command(char **dup, t_tools *tools)
// {
// 	t_command	*command;

// 	command = (t_command *)malloc(sizeof(t_command));
// 	if (command == NULL)
// 		return (NULL);
// 	command->args = array_dup(dup); //MALLOC
// 	if (command->args == NULL)
// 		return NULL;
//     command->redirection = init_redirection(command);
// 	command -> next = NULL;
// 	return (command);
// }

void	ft_lstadd_back_command(t_command *command_list, t_command *command)
{
	t_command	*temp;

	if (command == NULL)
		return ;
	if (command_list == NULL)
	{	
		command_list = command;
		command->next = NULL;
		return ;
	}
	temp = command_list;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = command;
}


/*
**	Initiates command_list according to pipe existance.
**	 If there is no pipe found, single command node is returned as command_list
**	otherwise everthing until "|" is copied to command->args in a while loop
**	TEST PURPOSE
*/
t_command	*ft_lstnew_command(char **dup, t_tools *tools)
{
	t_command	*command;
	char **temp_args;
	int i;
	static int pipe_index_position;

	i = 0;
	temp_args = array_dup(dup);
	command = (t_command *)malloc(sizeof(t_command));
	if (command == NULL)
		return (NULL);
	tools->command_list = command;
	if (count_pipes(temp_args) == 0)
	{
		command->args = temp_args; //MALLOC
		if (command->args == NULL)
		return NULL;
		command->redirection = init_redirection(command);
		command->next = NULL;
		return (command);
	}
	//printf("1i = %d\n", i);
	while (temp_args[i] != NULL)
	{
		printf("1pipe = %d\n", pipe_index_position);
	//	printf("%s %s %s %s %s\n", temp_args[0], temp_args[1], temp_args[2], temp_args[3], temp_args[4]);

		command->args = copy_content_until_pipe(temp_args, &pipe_index_position); //MALLOC
		printf("%s\n%s\n%s\n%s\n", command->args[0], command->args[1],command->args[2],command->args[3]);  
		if (command->args == NULL)
			return (NULL);
		printf("2pipe = %d\n", pipe_index_position);
		command->redirection = init_redirection(command);
		if (ft_strsame(temp_args[i], "|") == 1)
		{
			i++;
			command->next = (t_command *)malloc(sizeof(t_command));
			if (command->next == NULL)
				return (NULL);
			command = command->next;
		}
	}
	command = tools->command_list;
	return (command);
}

// void create_command_list(t_command *command_list, t_command *command)
// {
// 	t_command	*command;
// 	char **temp_args;
// 	static int i;
// 	int number_of_command_nodes;

// 	i = 0;
// 	temp_args = array_dup(dup);
// 	number_of_command_nodes = count_pipes(temp_args) + 1;
// 	command = (t_command *)malloc(sizeof(t_command));
// 	if (command == NULL)
// 		return (NULL);
// 	tools->command_list = command;
// 	while (temp_args[i] != NULL)
// 	{
// 		command->args = copy_content_until_pipe(temp_args, i); //MALLOC
// 		if (command->args == NULL)
// 			return (NULL);
// 		command->redirection = init_redirection(command);
// 		if (ft_strsame(temp->args[i], "|") == 1)
// 		{
// 			i++;
// 			command->next = (t_command *)malloc(sizeof(t_command));
// 			if (command->next == NULL)
// 				return (NULL);
// 			command = command->next;
// 		}
// 	}
// 	command = tools->command_list;
// 	return (command);
// }