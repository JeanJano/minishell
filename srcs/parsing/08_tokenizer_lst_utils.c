/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_tokenizer_lst_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/09 16:27:53 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok_lst	*lstnew_token(t_exec *exec)
{
	t_tok_lst	*result;

	result = malloc(sizeof(t_tok_lst));
	lstadd_back_malloc(exec, lstnew_malloc(result));
	result->args = NULL;
	result->input_fd = 0;
	result->in_file = NULL;
	result->delimiter = NULL;
	result->output_fd = 1;
	result->out_file = NULL;
	result->next = NULL;
	return (result);
}

t_tok_lst	*lstlast_token(t_tok_lst *lst)
{
	t_tok_lst	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}

void	lstadd_back_token(t_tok_lst **lst, t_tok_lst *new)
{
	t_tok_lst	*last;

	if (*lst)
	{
		last = lstlast_token(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	read_lst_token(t_tok_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("index=%d %d\n", i, lst->output_fd);
		lst = lst->next;
	}
}

int	ft_lstsize_token(t_tok_lst *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
