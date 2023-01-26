/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:48:00 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:18:09 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		result;

	n = nb;
	result = 1;
	if (n < 0)
	{
		result = result + 1;
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		result = result + ft_putnbr(n / 10);
		n = n % 10;
	}
	ft_putchar(n + '0');
	return (result);
}
