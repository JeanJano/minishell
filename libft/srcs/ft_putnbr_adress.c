/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_adress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:25:19 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:17:55 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long nb, unsigned long b, char *base)
{
	unsigned long	n;
	int				count;

	n = nb;
	count = 1;
	if (n > (b - 1))
	{
		count = count + ft_putnbr_base(n / b, b, base);
		n = n % b;
	}
	ft_putchar(base[n]);
	return (count);
}

int	ft_putnbr_adress(unsigned long nbr)
{
	int	count;

	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	count = count + ft_putnbr_base(nbr, 16, "0123456789abcdef");
	return (count);
}
