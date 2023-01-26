/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:13:24 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:19:09 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char)c && i)
	{
		i--;
	}
	if (str[i] == (char)c)
		return ((char *)str + (i));
	return (NULL);
}

// int main(void)
// {
//	char s[] = "tripouille";
// 	printf("%s\n", ft_strrchr(s, 't' + 256));
// 	printf("%s", strrchr(s, 't' + 256));
// 	// ft_strrchr("saluuut", 117);
// }