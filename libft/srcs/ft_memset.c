/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:55:12 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:17:01 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	size;

	size = n;
	while (n)
	{
		*(char *)s = c;
		s++;
		n--;
	}
	return (s - size);
}

// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
//     char str[5] = "allo";
// 	printf("%p", memset(str, 31, 1));
//     printf("%c", str[0]);
//     printf("%c", str[1]);
//     printf("%c", str[2]);
//     printf("%c", str[3]);
//     printf("%d", str[4]);
// }