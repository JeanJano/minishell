/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:14:32 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 17:36:34 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_newstrjoin(char *s1, char *s2)
{
	char	*newstr;

	newstr = ft_strjoin(s1, s2);
	free(s2);
	return (newstr);
}

void	close_fds(int fd_nbr, ...)
{
	va_list	args;
	int		next_fd;

	va_start(args, fd_nbr);
	next_fd = va_arg(args, int);
	while (fd_nbr)
	{
		close(next_fd);
		next_fd = va_arg(args, int);
		fd_nbr--;
	}
}

int	file_exist(char *file_name)
{
	if (!file_name)
		return (0);
	if (access(file_name, F_OK) == 0)
		return (1);
	return (0);
}

int	file_exec(char *file_name)
{
	if (!file_name)
		return (0);
	if (access(file_name, X_OK) == 0)
		return (1);
	return (0);
}

int	is_directory(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (S_ISDIR(statbuf.st_mode));
}
