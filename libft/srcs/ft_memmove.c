/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:12 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:58 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		size;
	char		*dest_end;
	const char	*src_end;

	size = len;
	if ((char *)dest < (char *)src)
	{
		while (size)
		{
			*(char *)dest++ = *(char *)src++;
			size--;
		}
		return (dest - len);
	}
	else
	{
		dest_end = dest + (len - 1);
		src_end = src + (len - 1);
		while (size)
		{
			*(char *)dest_end-- = *(char *)src_end--;
			size--;
		}
		return (dest);
	}
}

// #define SIZE 21

// char	target[SIZE] = "a shiny white sphere";

// int	main(void)
// {
// 	char *p = target + 8;      /* p points at the starting character
//                           of the word we want to replace */
// 	char *source = target + 2; /* start of "shiny" */

// 	printf("Before memmove, target is \"%s\"\n", target);
// 	ft_memmove(p, source, 5);
// 	printf("After memmove, target becomes \"%s\"\n", target);
// }