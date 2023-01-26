/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_env_lst_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/12/09 16:25:46 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_lst	*lstnew_env(char *name, char *value)
{
	t_env_lst	*result;

	result = malloc(sizeof(t_env_lst));
	if (!result)
		return (NULL);
	result->name = name;
	result->value = value;
	result->next = NULL;
	return (result);
}

t_env_lst	*lstlast_env(t_env_lst *lst)
{
	t_env_lst	*head;

	if (lst == NULL)
		return (0);
	head = lst;
	while (head->next)
		head = head->next;
	return (head);
}

void	lstadd_back_env(t_env_lst **lst, t_env_lst *new)
{
	t_env_lst	*last;

	if (!new)
	{
		free_env_lst(*lst);
		exit(1);
	}
	if (*lst)
	{
		last = lstlast_env(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void	free_env_lst(t_env_lst *env_lst)
{
	t_env_lst	*tmp;

	while (env_lst)
	{
		tmp = env_lst->next;
		free(env_lst->name);
		free(env_lst->value);
		free(env_lst);
		env_lst = tmp;
	}
}
