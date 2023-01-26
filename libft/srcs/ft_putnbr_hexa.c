/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:23:22 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:23:20 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_pos(long nb, long b, char *base)
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
	if (n > (b - 1))
	{
		result = result + ft_putnbr_base_pos(n / b, b, base);
		n = n % b;
	}
	ft_putchar(base[n]);
	return (result);
}

static int	ft_putnbr_base_neg(long nb, long b, char *base)
{
	long	n;
	int		result;

	n = nb;
	result = 1;
	if (n > (b - 1))
	{
		result = result + ft_putnbr_base_neg(n / b, b, base);
		n = n % b;
	}
	ft_putchar(base[n]);
	return (result);
}

int	ft_putnbr_hexa(long nbr, int upper)
{
	int	count;

	count = 0;
	if (!upper)
	{
		if (nbr < 0)
			count = ft_putnbr_base_neg(4294967295 + nbr + 1, 16,
					"0123456789abcdef");
		else
			count = ft_putnbr_base_pos(nbr, 16, "0123456789abcdef");
	}
	else
	{
		if (nbr < 0)
			count = ft_putnbr_base_neg(4294967295 + nbr + 1, 16,
					"0123456789ABCDEF");
		else
			count = ft_putnbr_base_pos(nbr, 16, "0123456789ABCDEF");
	}
	return (count);
}
