/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/09 16:27:42 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_env(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '$' || !str[i + 1])
		return (0);
	if (!ft_isalnum(str[i + 1]) && str[i + 1] != '_' && str[i + 1] != '?'
		&& str[i + 1] != '\'' && str[i + 1] != '"')
		return (0);
	return (1);
}

char	*expand_env_name(char *str)
{
	int		i;
	char	*env_name;

	i = -1;
	if (str[0] == '?')
		return (ft_strdup("?"));
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (ft_strdup(""));
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			break ;
	}
	env_name = malloc((i + 1) * sizeof(char));
	if (!env_name)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			break ;
		env_name[i] = str[i];
	}
	env_name[i] = 0;
	return (env_name);
}

void	go_end_env_name(char **str)
{
	if (**str == '?')
	{
		(*str)++;
		return ;
	}
	if (!ft_isalpha(**str) && **str != '_')
	{
		(*str)++;
		return ;
	}
	while (**str)
	{
		if (!ft_isalnum(**str) && **str != '_')
			break ;
		(*str)++;
	}
}
