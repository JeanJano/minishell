/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/16 22:48:04 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_name_size(char *env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i] == '=')
			break ;
		i++;
	}
	if (env[i - 1] == '+')
		i--;
	return (i);
}

char	*get_env_name(char *env)
{
	int		i;
	char	*name;

	if (env[0] == '=')
		return (NULL);
	i = get_env_name_size(env);
	name = malloc((i + 1) * sizeof(char));
	if (!name)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (env[i] == '=' || (env[i] == '+' && env[i + 1] == '='))
			break ;
		name[i] = env[i];
		i++;
	}
	name[i] = 0;
	if (ft_strlen(name) == 0)
	{
		free(name);
		return (NULL);
	}
	return (name);
}

t_env_lst	*get_env_lst(char **env)
{
	t_env_lst	*env_lst;
	char		*value;
	char		*name;
	int			i;

	i = 0;
	env_lst = NULL;
	while (env[i])
	{
		name = get_env_name(env[i]);
		value = ft_strdup(getenv(name));
		lstadd_back_env(&env_lst, lstnew_env(name, value));
		i++;
	}
	return (env_lst);
}

void	change_env_value(char *name, char *new_value, t_exec *exec)
{
	t_env_lst	*tmp;

	tmp = exec->env_lst;
	while (tmp)
	{
		if (ft_strmatch(tmp->name, name))
		{
			free(tmp->value);
			tmp->value = new_value;
			return ;
		}
		tmp = tmp->next;
	}
	lstadd_back_env(&exec->env_lst, lstnew_env(ft_strdup(name), new_value));
}

char	*get_env_value(char *name, t_exec *exec)
{
	t_env_lst	*env_lst;

	env_lst = exec->env_lst;
	while (env_lst)
	{
		if (ft_strmatch(name, env_lst->name))
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return ("");
}
