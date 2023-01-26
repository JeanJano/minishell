/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:54:45 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:22 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(long nbr)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

void	put_in_string(char *r, int nbr, int *i)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		r[*i] = '-';
		(*i)++;
		n = -n;
	}
	if (n > 9)
	{
		put_in_string(r, n / 10, i);
		n = n % 10;
	}
	r[*i] = n + '0';
	(*i)++;
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((ft_get_size(nbr) + 1) * sizeof(char));
	put_in_string(result, nbr, &i);
	result[i] = 0;
	return (result);
}
