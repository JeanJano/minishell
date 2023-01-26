/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:55:25 by jsauvage          #+#    #+#             */
/*   Updated: 2022/12/15 21:06:04 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	append(t_tok_lst *tok_lst)
{
	int		file_fd;
	char	*file;

	file = lstlast_array(tok_lst->out_file)->content;
	file_fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (tok_lst->args != NULL)
		dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}

void	here_doc(t_tok_lst *tok_lst)
{
	int			fd_here_doc;
	t_array_lst	*del;

	del = lstlast_array(tok_lst->delimiter);
	fd_here_doc = open(del->content2, O_RDONLY);
	dup2(fd_here_doc, STDIN_FILENO);
	close(fd_here_doc);
}

void	redir_out(t_tok_lst *tok_lst)
{
	int		file_fd;
	char	*file;

	file = lstlast_array(tok_lst->out_file)->content;
	file_fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (tok_lst->args != NULL)
		dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
}

void	redir_in(t_tok_lst *tok_lst)
{
	int		file_fd;
	char	*file;

	file = lstlast_array(tok_lst->in_file)->content;
	file_fd = open(file, O_RDONLY);
	if (tok_lst->args != NULL)
		dup2(file_fd, STDIN_FILENO);
	close(file_fd);
}
