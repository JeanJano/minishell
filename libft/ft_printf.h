/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:52:12 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:28:51 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_putnbr_hexa(long nbr, int upper);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr_adress(unsigned long nbr);

#endif