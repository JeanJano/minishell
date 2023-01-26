/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:39:26 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:51 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	while (size)
	{
		if (*(unsigned char *)pointer1 > *(unsigned char *)pointer2)
			return (1);
		if (*(unsigned char *)pointer1 < *(unsigned char *)pointer2)
			return (-1);
		pointer1++;
		pointer2++;
		size--;
	}
	return (0);
}

// int main(void)
// {
// 	 int array1[] = { 5450, 3, 20, 63, 21 };
//      int array2[] = { 5450, 3, 20, 63, 21 };
// 	//char array1[5] = "arr9";
//    // char array2[5] = "arr7";
//     size_t size = 5 * sizeof(array1[0]);
// 	printf("%d ", ft_memcmp(array1, array2, size));
// 	//printf("%d", memcmp(array1, array2, size));
// }