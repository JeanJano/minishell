/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:20:21 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:55 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	int	count;

	count = size;
	while (count)
	{
		*(char *)destination = *(char *)source;
		destination++;
		source++;
		count--;
	}
	return (destination - size);
}

// int	main(void)
// {
// 	char str[] = "zyxwvutsrqponmlkjihgfedcba";
// 	char dest[30];
// 	char dest2[30];
// 	char *adress = ft_memcpy(dest, str, 14);
// 	printf("%s\n", adress);
// 	// printf("%p\n", memcpy(dest2, str, 14));
// 	// printf("%s\n", dest);
// 	// printf("%s", dest2);
// }