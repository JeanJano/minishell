/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:15 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:21:05 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
// 	int fd;

// 	fd = open("test.json", O_RDWR);
// 	if (fd == -1)
// 		write(1, "Error\n", 11);
// 	ft_putchar_fd('l', fd);
// 	close(fd);
// }