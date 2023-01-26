/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/15 18:41:22 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **args, t_env_lst *env_lst)
{
	if (args[1])
	{
		ft_putstr_fd("env: too many arguments\n", 2);
		return (1);
	}
	while (env_lst)
	{
		printf("%s=%s\n", env_lst->name, env_lst->value);
		env_lst = env_lst->next;
	}
	return (0);
}

int	ft_export(t_exec *exec, char **args)
{
	int		return_value;
	int		i;

	i = 0;
	return_value = 0;
	while (args[i])
	{
		return_value = export_env(args[i], exec);
		i++;
	}
	return (return_value);
}

int	ft_unset(t_env_lst **env_lst, char **args)
{
	int			i;

	i = 1;
	while (args[i])
	{
		unset_env(args[i], env_lst);
		i++;
	}
	return (0);
}
