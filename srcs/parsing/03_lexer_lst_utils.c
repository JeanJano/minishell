/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_lexer_lst_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/09 16:27:24 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lex_lst	*lstnew_lex(char *content, int operator, t_exec *exec)
{
	t_lex_lst	*result;

	lstadd_back_malloc(exec, lstnew_malloc(content));
	result = malloc(sizeof(t_lex_lst));
	lstadd_back_malloc(exec, lstnew_malloc(result));
	result->content = content;
	result->operator = operator;
	result->next = NULL;
	return (result);
}

t_lex_lst	*lstlast_lexer(t_lex_lst *lst)
{
	t_lex_lst	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}

void	lstadd_back_lex(t_lex_lst **lst, t_lex_lst *new)
{
	t_lex_lst	*last;

	if (*lst)
	{
		last = lstlast_lexer(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	read_lst(t_lex_lst *lst)
{
	while (lst)
	{
		printf("type=%d %s\n", lst->operator, lst->content);
		lst = lst->next;
	}
}
