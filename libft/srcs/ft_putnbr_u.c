/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:25:24 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:18:06 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nb)
{
	unsigned long	n;
	int				result;

	n = nb;
	result = 1;
	if (n > 9)
	{
		result = result + ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
	return (result);
}
