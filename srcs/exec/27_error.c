/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:55:43 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_message_127(char *command)
{
	if (!command)
		return ;
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	error_message(char *file, char *message)
{
	if (!file || !message)
		return ;
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
}

static void	error_status(t_tok_lst *tok_lst)
{
	char	*file_error;

	file_error = get_wrong_access(tok_lst);
	if (g_status == 1 && file_exist(file_error) == 0)
		error_message(file_error, "No such file or directory\n");
	else if (g_status == 1 && file_exec(file_error) == 0)
		error_message(file_error, "Permission denied\n");
	else if (g_status == 126 && is_directory(file_error) == 1)
		error_message(file_error, "Is a directory\n");
	else if (g_status == 126 && file_exist(tok_lst->args->content) == 0)
		error_message(tok_lst->args->content, "No such file or directory\n");
	else if (g_status == 126 && is_directory(tok_lst->args->content))
		error_message(tok_lst->args->content, "Is a directory\n");
	else if (g_status == 126)
		error_message(tok_lst->args->content, "Permission denied\n");
	else if (g_status == 127 && (tok_lst->args->content[0] == '/'
			|| tok_lst->args->content[0] == '.'))
		error_message(tok_lst->args->content, "No such file or directory\n");
	else if (g_status == 127)
		error_message_127(tok_lst->args->content);
}

void	error_manager(t_exec exec)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (exec.tok_lst && waitpid(exec.pid[i], &status, 0) > 0)
	{
		if (WTERMSIG(status) == 2)
			ft_putstr_fd("\n", 1);
		else if (WTERMSIG(status) == 3)
			ft_putstr_fd(" Quit (core dumped)\n", 1);
		if (WIFEXITED(status))
			g_status = WEXITSTATUS(status);
		error_status(exec.tok_lst);
		exec.tok_lst = exec.tok_lst->next;
		i++;
	}
}

int	error_here_doc(t_exec *exec, int stdin_fd)
{
	if (g_status == 777)
	{
		heredoc_rm(exec->tok_lst);
		dup2(stdin_fd, 0);
		close(stdin_fd);
		g_status = 130;
		return (0);
	}
	return (1);
}
