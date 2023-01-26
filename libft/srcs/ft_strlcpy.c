/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:50:52 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:18:47 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	*src;
// 	char	dest[10] = "bonjour";
// 	char	dest2[10] = "bonjour";

// 	src = "lorem";
// 	printf("%ld ", strlcpy(dest, src, 0));
// 	printf("%ld ", ft_strlcpy(dest2, src, 0));
// 	printf("%s-%s", dest, dest2);
// }

// gcc -o test file.c -lbsd