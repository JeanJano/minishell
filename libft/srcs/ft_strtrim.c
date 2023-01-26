/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:23:32 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:19:11 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set_forward(char s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_check_set_backward(char s1, char const *set)
{
	while (*set)
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i_start;
	int		i_end;
	int		total_size;
	int		i;

	i_start = 0;
	i_end = ft_strlen(s1);
	total_size = ft_strlen(s1);
	i = 0;
	while (ft_check_set_forward(s1[i_start], set))
		i_start++;
	if (i_start == total_size)
	{
		result = malloc(1);
		result[0] = 0;
		return (result);
	}
	while (ft_check_set_backward(s1[i_end - 1], set))
		i_end--;
	result = malloc((total_size - i_start) - (total_size - i_end) + 1);
	while (i_start < i_end)
		result[i++] = s1[i_start++];
	result[i] = 0;
	return (result);
}

// int	main(void)
// {
//		//char s1[] = "          ";
//		char *result = ft_strtrim("   xxx   xxx", " ");
//		printf("%s", result);
// }
