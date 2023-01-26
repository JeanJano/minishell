/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/09 01:06:18 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char *readline_str)
{
	if (readline_str[1] && readline_str[0] == '<' && readline_str[1] == '<')
		return (1);
	if (readline_str[1] && readline_str[0] == '>' && readline_str[1] == '>')
		return (1);
	if (readline_str[0] == '|')
		return (1);
	if (readline_str[0] == '<')
		return (1);
	if (readline_str[0] == '>')
		return (1);
	return (0);
}

int	get_word_size(char *word)
{
	char	quote_type;
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	quote_type = 0;
	while (*word)
	{
		if (quote == 0 && (is_operator(word) || ft_isspace(*word)))
			break ;
		if ((*word == '\'' || *word == '\"') && quote == 0)
		{
			quote++;
			quote_type = *word;
		}
		else if (quote == 1 && *word == quote_type)
		{
			quote = 0;
			quote_type = 0;
		}
		i++;
		word++;
	}
	return (i);
}

void	get_word(char *word, char **result)
{
	char	quote_type;
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	quote_type = 0;
	while (*word)
	{
		if (quote == 0 && (is_operator(word) || ft_isspace(*word)))
			break ;
		if ((*word == '\'' || *word == '\"') && quote == 0)
		{
			quote++;
			quote_type = *word;
		}
		else if (quote == 1 && *word == quote_type)
		{
			quote = 0;
			quote_type = 0;
		}
		(*result)[i++] = *word++;
	}
	(*result)[i] = 0;
}

void	go_to_word_end(char **readline_str)
{
	char	quote_type;
	int		quote;

	quote = 0;
	quote_type = 0;
	while (**readline_str)
	{
		if (quote == 0 && is_operator(*readline_str))
			break ;
		if (ft_isspace(**readline_str) && quote == 0)
			break ;
		if ((**readline_str == '\'' || **readline_str == '\"') && quote == 0)
		{
			quote++;
			quote_type = **readline_str;
		}
		else if (quote == 1 && **readline_str == quote_type)
		{
			quote = 0;
			quote_type = 0;
		}
		(*readline_str)++;
	}
}
