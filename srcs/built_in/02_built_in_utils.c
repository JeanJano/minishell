/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_built_in_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:01:57 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/09 01:02:23 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_built_in(t_exec *exec)
{
	char	**args;
	int		return_value;

	return_value = 0;
	args = lst_to_str_array(exec->tok_lst->args, exec);
	if (ft_strmatch(args[0], "exit"))
		return_value = ft_exit(args, exec);
	else if (ft_strmatch(args[0], "export"))
		return_value = ft_export(exec, args);
	else if (ft_strmatch(args[0], "unset"))
		return_value = ft_unset(&exec->env_lst, args);
	else if (ft_strmatch(args[0], "env"))
		return_value = ft_env(args, exec->env_lst);
	else if (ft_strmatch(args[0], "cd"))
		return_value = ft_cd(args, exec);
	else if (ft_strmatch(args[0], "pwd"))
		return_value = ft_pwd(exec);
	else if (ft_strmatch(args[0], "echo"))
		return_value = ft_echo(args);
	return (return_value);
}

int	is_built_in(char *command)
{
	if (ft_strmatch(command, "exit"))
		return (1);
	if (ft_strmatch(command, "export"))
		return (1);
	if (ft_strmatch(command, "unset"))
		return (1);
	if (ft_strmatch(command, "env"))
		return (1);
	if (ft_strmatch(command, "cd"))
		return (1);
	if (ft_strmatch(command, "pwd"))
		return (1);
	if (ft_strmatch(command, "echo"))
		return (1);
	return (0);
}

int	is_built_in_no_fork(char *command)
{
	if (ft_strmatch(command, "exit"))
		return (1);
	if (ft_strmatch(command, "export"))
		return (1);
	if (ft_strmatch(command, "unset"))
		return (1);
	if (ft_strmatch(command, "cd"))
		return (1);
	return (0);
}
