/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:37:42 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:49 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int c, size_t size)
{
	while (size)
	{
		if (*(char *)memoryBlock == (char)c)
			return ((void *)memoryBlock);
		size--;
		memoryBlock++;
	}
	return (NULL);
}

// int main(void)
// {
//     char data[] = {0, 1, 2 ,3 ,4 ,5};
//     const unsigned int size = 10;
// 	char *adress = ft_memchr(data, 2 + 256, 3);
//	//printf("%d\n", 3 + 255);
// 	printf("%d", *adress);
// }