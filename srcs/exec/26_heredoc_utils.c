/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26_heredoc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:50:56 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 17:43:22 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_heredoc(t_exec *exec)
{
	t_tok_lst	*tmp;
	int			i;

	tmp = exec->tok_lst;
	i = 0;
	while (i < exec->nb_command)
	{
		if (tmp->delimiter)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static char	*get_heredoc_name(int i, t_exec *exec)
{
	char	*heredoc_name;
	char	*index;

	index = ft_itoa(i);
	heredoc_name = ft_strjoin(".heredoc", index);
	lstadd_back_malloc(exec, lstnew_malloc(heredoc_name));
	free(index);
	return (heredoc_name);
}

static void	get_here_doc_file(char *del, char *name_file, t_exec *exec)
{
	char	*line;
	int		here_doc_fd;

	here_doc_fd = open(name_file, O_CREAT | O_RDWR, 0666);
	if (here_doc_fd == -1)
		return ((void)perror(name_file));
	del = ft_strjoin(del, "\n");
	lstadd_back_malloc(exec, lstnew_malloc(del));
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0);
		if (!line || ft_strmatch(del, line))
		{
			if (!line)
				ft_putstr_fd("\n", 0);
			free(line);
			break ;
		}
		ft_putstr_fd(line, here_doc_fd);
		free(line);
	}
	close(here_doc_fd);
}

void	here_doc_manage(t_exec *exec)
{
	t_tok_lst	*tok_head;
	t_array_lst	*del_head;
	char		*here_doc_name;
	int			i;

	i = 0;
	tok_head = exec->tok_lst;
	signal_manager_hd();
	while (exec->tok_lst)
	{
		del_head = exec->tok_lst->delimiter;
		while (exec->tok_lst->delimiter)
		{
			here_doc_name = get_heredoc_name(i, exec);
			get_here_doc_file(exec->tok_lst->delimiter->content,
				here_doc_name, exec);
			exec->tok_lst->delimiter->content2 = here_doc_name;
			exec->tok_lst->delimiter = exec->tok_lst->delimiter->next;
			i++;
		}
		exec->tok_lst->delimiter = del_head;
		exec->tok_lst = exec->tok_lst->next;
	}
	exec->tok_lst = tok_head;
}

void	heredoc_rm(t_tok_lst *tok_lst)
{
	while (tok_lst)
	{
		while (tok_lst->delimiter)
		{
			unlink(tok_lst->delimiter->content2);
			tok_lst->delimiter = tok_lst->delimiter->next;
		}
		tok_lst = tok_lst->next;
	}
}
