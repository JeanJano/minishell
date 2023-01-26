/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_env(char **str, char **result, t_exec *exec)
{
	char	*env_name;
	char	*env_value;

	(*str)++;
	env_name = expand_env_name(*str);
	if (!env_name)
		free_exit(exec, 1, FALSE);
	if (ft_strmatch(env_name, "?"))
	{
		env_value = ft_itoa(g_status);
		lstadd_back_malloc(exec, lstnew_malloc(env_value));
	}
	else
		env_value = get_env_value(env_name, exec);
	if (ft_strlen(env_value) != 0)
	{
		*result = ft_strjoin(*result, env_value);
		lstadd_back_malloc(exec, lstnew_malloc(*result));
	}
	go_end_env_name(str);
	free(env_name);
}

char	*expand_quote_env(char *str, t_exec *exec)
{
	char	quote_type;
	char	*result;

	result = "";
	quote_type = 0;
	while (*str)
	{
		if ((*str == '\'' || *str == '\"') && quote_type == 0)
		{
			quote_type = *str;
			str++;
		}
		else if (*str == quote_type && quote_type != 0)
		{
			quote_type = 0;
			str++;
		}
		else if (quote_type != '\'' && is_env(str))
			expand_env(&str, &result, exec);
		else
			result = strjoin_char(result, *str++, exec);
	}
	return (result);
}

void	expander(t_exec *exec)
{
	t_lex_lst	*lex_lst;

	lex_lst = exec->lex_lst;
	while (lex_lst)
	{
		if (lex_lst->operator == HERE_DOC)
			lex_lst = lex_lst->next;
		else if (lex_lst->operator == WORD)
			lex_lst->content = expand_quote_env(lex_lst->content, exec);
		lex_lst = lex_lst->next;
	}
}
