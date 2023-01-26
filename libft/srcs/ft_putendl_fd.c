/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:20 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:17:48 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	int fd;

// 	fd = open("test.json", O_RDWR);
// 	if (fd == -1)
// 		write(1, "Error\n", 11);
// 	ft_putendl("hgdfkgjkfhgfkjfhgd", fd);
// 	close(fd);
// }