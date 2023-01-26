/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:51:15 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:19:14 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(char const *s, unsigned int start, size_t len)
{
	int				count;
	unsigned int	size;

	count = 0;
	size = 0;
	while (s[size])
		size++;
	while (start < size && len)
	{
		len--;
		start++;
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		i;
	int		size;

	i = 0;
	size = ft_get_size(s, start, len);
	result = malloc((size + 1) * sizeof(char));
	if (result == 0)
		return (NULL);
	while (size && s[start] && len)
	{
		result[i] = s[start];
		i++;
		start++;
		len--;
		size--;
	}
	result[i] = 0;
	return (result);
}

// int main(void)
// {
// 	// char * str = ft_strdup("1");
// 	char *result = ft_substr("tripouille", 100, 1);
// 	printf("%s", result);
// }