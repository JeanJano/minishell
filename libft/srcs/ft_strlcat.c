/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 18:04:42 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:18:44 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_size;
	unsigned int	dst_size;

	i = 0;
	j = 0;
	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (dst_size > size)
		return (src_size + size);
	while (dst[i])
		i++;
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (src_size + dst_size);
}

// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// int	main(void)
// {
//	char dest[10] = "";
//	char dest2[10] = "";
//	char src[] = "1234";
//	int size = 0;
//	printf("real : %lu\n", strlcat(dest, src, size));
// 	printf("real : %s\n", dest);
//	printf("%lu\n", ft_strlcat(dest2, src, size));
// 	printf("%s\n", dest2);
// 	return (0);
// }
