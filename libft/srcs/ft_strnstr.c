/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:51:07 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:19:03 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	long unsigned int	count;

	count = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while (*str1 && count <= len)
	{
		if ((count + ft_strlen(str2)) <= len && ft_strncmp(str1, str2,
				ft_strlen(str2)) == 0)
			return ((char *)str1);
		str1++;
		count++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *largestring = "salut allo";
//     const char *smallstring = "allo";
// 	int size = 9;
//     char *ptr;
//     char *ptr2;

//     // ft_strnstr(largestring, smallstring, 7);
//     ptr = ft_strnstr(largestring, smallstring, size);
//     ptr2 = strnstr(largestring, smallstring, size);
// 	printf("%s-", ptr);
// 	printf("%s", ptr2);
// }
