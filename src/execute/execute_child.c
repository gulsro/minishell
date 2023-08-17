#include "../../include/minishell.h"

char *join_command_to_path(char *path, char *main_command)
{
	char *path_with_slash_at_the_end;
	char *joined_command;

	path_with_slash_at_the_end = ft_strjoin(path, "/"); //MALLOC
	if (path_with_slash_at_the_end == NULL)
		return (NULL);
	joined_command = ft_strjoin(path_with_slash_at_the_end, main_command);
	free(path_with_slash_at_the_end);
	if (joined_command == NULL)
		return (NULL);
	return (joined_command);
}

char **get_paths(t_tools *tools)
{
	char **path_arr;
	char *path_str;
	int i;

	i = 0;
	path_str = get_value_from_env_node("PATH", tools->env_list); //MALLOC
	if (path_str == NULL)
		return(ft_putendl_fd("Path can not be found", STDERR_FILENO), NULL);
	path_arr = ft_split(path_str, ':'); //MALLOC
	free(path_str);
	if (path_arr == NULL)
		return (NULL);
	return (path_arr);
}

/*
**	execute_child() first searchs the command in current directory. 
**	If finds, does execution, otherwise it searchs the command in PATH
*/
void execute_child(t_tools *tools)
{
	t_command *command;
	char **path_arr;
	char *full_path_command;
	int i;

	i = 0;
	command = tools->command_list;
	if (access(command->args[0], F_OK) == 0)
		execve(command->args[0], command->args, tools->env);
	path_arr = get_paths(tools);
	while (path_arr[i] != NULL)
	{
		full_path_command = join_command_to_path(path_arr[i], command->args[0]);
		printf("%s\n", full_path_command);
		if (full_path_command == NULL)
			error_exit("execute_child failed", 1);
		if (access(full_path_command, F_OK) == 0)
			break ;
		free(full_path_command);
		i++;
	}
	execve(full_path_command, command->args, tools->env);
	free(full_path_command);
	//free all
	//exit code?
	error_exit("child exec bad", 1);
}
