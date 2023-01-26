/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:21:04 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:19:01 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	unsigned int	i;

	i = 0;
	if (length == 0)
		return (0);
	while (length - 1 && *s1 && *s1 == *s2)
	{
		length--;
		s1++;
		s2++;
	}
	i = *s1 - *s2;
	return (i);
}

// int main(void)
// {
// 	char s1[] = "a";
// 	char s2[] = "ghf";
// 	int size = 3;

// 	printf("%d\n", strncmp(s1, s2, size));
// 	printf("%d", ft_strncmp(s1, s2, size));
// }