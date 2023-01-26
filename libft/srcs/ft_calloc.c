/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:49:44 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:05 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set_zero(void *result, int total_count)
{
	while (total_count)
	{
		*(char *)result = 0;
		result++;
		total_count--;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*result;
	int		total_count;

	result = NULL;
	total_count = elementCount * elementSize;
	if (elementCount == 0 || elementSize == 0)
	{
		result = malloc(0);
		return (result);
	}
	if (total_count / elementCount != elementSize)
		return (result);
	result = malloc(total_count);
	if (result)
		ft_set_zero(result, total_count);
	return (result);
}

// int	main(void)
// {
// 	int i = 0;
// 	char *str;
// 	str = (char *)ft_calloc(2147000000, 0);
// 	// printf("%s\n", str);
// 	free(str);
// }

// alloc memory and write null byte