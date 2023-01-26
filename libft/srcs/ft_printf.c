/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:47:51 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:28:23 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_var_type(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd')
		count = count + ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = count + ft_putnbr_u(va_arg(args, int));
	else if (c == 'p')
		count = count + ft_putnbr_adress(va_arg(args, long int));
	else if (c == 'x')
		count = count + ft_putnbr_hexa(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count = count + ft_putnbr_hexa(va_arg(args, unsigned int), 1);
	else if (c == 's')
		count = count + ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		count = count + ft_putchar(va_arg(args, int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				count = count + ft_putchar('%');
			else
				count = count + ft_get_var_type(str[i], args);
			i++;
		}
		else
			count = count + ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	// char *ptr = NULL;
// 	// printf("%d", printf("%%%"));
// 	ft_printf("%%%");
// }