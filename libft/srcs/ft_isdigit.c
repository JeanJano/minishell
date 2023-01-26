/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:49:58 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:16 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (2048);
	}
	return (0);
}

// int	main(void)
// {
// 	char c;
// 	c = '9';
// 	printf("Result when uppercase alphabet is passed: %d", ft_isdigit(c));
// 	printf("\nResult when uppercase alphabet is passed: %d", isdigit(c));
// 	return (0);
// }