/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:14:07 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:08 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
	{
		return (8);
	}
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	printf("Result when uppercase alphabet is passed: %d", ft_isalnum(c));
// 	printf("\nResult when uppercase alphabet is passed: %d", isalnum(c));
// 	return (0);
// }
