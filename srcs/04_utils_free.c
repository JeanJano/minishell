/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_utils_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:03:32 by jsauvage          #+#    #+#             */
/*   Updated: 2022/12/15 19:57:56 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_exec *exec, int code_exit, bool close_fd)
{
	if (close_fd)
		close_fds(3, exec->pipe_fd[0], exec->pipe_fd[1], exec->stdin_fd);
	free_lst_malloc(exec->mal_lst);
	free_env_lst(exec->env_lst);
	exit(code_exit);
}

void	free_array(char **arr)
{
	int	count;
	int	i;

	count = 0;
	while (arr[count])
		count++;
	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
