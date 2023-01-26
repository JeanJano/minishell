/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_env_built_in_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 01:01:57 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/09 01:02:49 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env_name(char *env_name)
{
	int	i;

	i = 0;
	if (env_name[i] && !ft_isalpha(env_name[i]) && env_name[i] != '_')
		return (1);
	i++;
	while (env_name[i])
	{
		if (!ft_isalnum(env_name[i]) && env_name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

char	*get_env_str_value(char *env)
{
	char	*value;
	int		i;

	i = 0;
	while (*env && *env != '=')
		env++;
	if (*env != '=')
		return (NULL);
	env++;
	while (env[i])
		i++;
	value = malloc((i + 1) * sizeof(char));
	if (!value)
		return (NULL);
	i = 0;
	while (env[i])
	{
		value[i] = env[i];
		i++;
	}
	value[i] = 0;
	return (value);
}

int	is_concatenate(char *env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == '+' && env[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	export_env(char *arg, t_exec *exec)
{
	char	*env_value;
	char	*name;

	name = get_env_name(arg);
	if (!name || check_env_name(name))
	{
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(name);
		return (1);
	}
	env_value = get_env_str_value(arg);
	if (!env_value)
	{
		free(name);
		return (0);
	}
	if (is_concatenate(arg))
		env_value = ft_newstrjoin(get_env_value(name, exec), env_value);
	change_env_value(name, env_value, exec);
	free(name);
	return (0);
}

void	unset_env(char *arg, t_env_lst **env_lst)
{
	t_env_lst	*tmp_previous;
	t_env_lst	*env_head;

	tmp_previous = NULL;
	env_head = *env_lst;
	while (env_head)
	{
		if (ft_strmatch(arg, env_head->name))
		{
			if (!tmp_previous)
				*env_lst = (*env_lst)->next;
			else
				tmp_previous->next = env_head->next;
			free(env_head->name);
			free(env_head->value);
			free(env_head);
			return ;
		}
		tmp_previous = env_head;
		env_head = env_head->next;
	}
}
