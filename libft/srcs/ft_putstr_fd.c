/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:28 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:18:15 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	int fd;

// 	fd = open("test.json", O_RDWR);
// 	if (fd == -1)
// 		write(1, "Error\n", 11);
// 	ft_putstr_fd("salut", fd);
// 	close(fd);
// }