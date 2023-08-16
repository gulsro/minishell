#include "../../include/minishell.h"

int check_first_char_dollar(char *string)
{
	if (*string != '$')
		return (0);
	else
		return (1);
}

/*
**	expand_string() handles $? and $ENV_VAR
*/
char *expand_string(char *string, t_tools *tools)
{
	t_command	*command;
	char		*return_val;
	int			i;

	command = tools->command_list;
	if (ft_strsame(string, "$?") == 1)
	{
		return_val = ft_itoa(glob_exit_status); //MALLOCCC
		return (return_val);
	}
	i = 0;
	while (tools->env_list[i] != NULL)
	{
		if (ft_strsame(string + 1, tools->env_list[i]->key) == 1)
		{
			return_val = get_value_from_env_node(tools->env_list[i]->key, tools->env_list); //MALLOCCC
			return (return_val);
		}
		i++;
	}
	return (NULL);
}
