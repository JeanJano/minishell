/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_malloc_lst_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent  <rvincent@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/11/13 02:50:11 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mal_lst	*lstnew_malloc(void *adr)
{
	t_mal_lst	*result;

	if (!adr)
		return (NULL);
	result = malloc(sizeof(t_mal_lst));
	if (!result)
		return (NULL);
	result->adr = adr;
	result->next = NULL;
	return (result);
}

t_mal_lst	*lstlast_malloc(t_mal_lst *lst)
{
	t_mal_lst	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}

void	lstadd_back_malloc(t_exec *exec, t_mal_lst *new)
{
	t_mal_lst	*last;

	if (!new)
		free_exit(exec, 1, FALSE);
	if (exec->mal_lst)
	{
		last = lstlast_malloc(exec->mal_lst);
		last->next = new;
	}
	else
		exec->mal_lst = new;
}

void	free_lst_malloc(t_mal_lst *lst)
{
	t_mal_lst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->adr);
		free(lst);
		lst = tmp;
	}
}
