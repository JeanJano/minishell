/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:14:18 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipex_exec(t_exec *exec)
{
	t_tok_lst	*head;
	int			i;

	head = exec->tok_lst;
	i = 0;
	while (i < exec->nb_command)
	{
		if (pipe(exec->pipe_fd) == -1)
			free_exit(exec, 1, FALSE);
		exec->pid[i] = fork();
		if (exec->pid[i] < 0)
			free_exit(exec, 1, TRUE);
		signal(SIGQUIT, sig_process);
		signal(SIGINT, sig_process);
		if (exec->pid[i] == 0)
			exec_token(exec, i);
		dup2(exec->pipe_fd[0], STDIN_FILENO);
		close_fds(2, exec->pipe_fd[0], exec->pipe_fd[1]);
		i++;
		exec->tok_lst = exec->tok_lst->next;
	}
	exec->tok_lst = head;
}

void	init_exec(t_exec *exec)
{
	exec->nb_command = ft_lstsize_token(exec->tok_lst);
	exec->pid = malloc(exec->nb_command * sizeof(pid_t));
	lstadd_back_malloc(exec, lstnew_malloc(exec->pid));
	exec->here_doc_lst = NULL;
}

void	exec(t_exec *exec)
{
	exec->stdin_fd = dup(0);
	if (check_heredoc(exec) == 1)
	{
		here_doc_manage(exec);
		if (error_here_doc(exec, exec->stdin_fd) == 0)
			return ;
	}
	if (exec->nb_command == 1 && exec->tok_lst->args
		&& is_built_in_no_fork(exec->tok_lst->args->content))
	{
		built_in_error_manage(exec);
		close(exec->stdin_fd);
		g_status = exec_built_in(exec);
		return ;
	}
	if (exec->nb_command > 0)
		pipex_exec(exec);
	error_manager(*exec);
	heredoc_rm(exec->tok_lst);
	dup2(exec->stdin_fd, 0);
	close(exec->stdin_fd);
}
