/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent  <rvincent@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/11 19:22:49 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_greater_long_long(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+')
		nbr++;
	while (nbr[i] == '0')
		nbr++;
	if (ft_strlen(nbr) > 20)
		return (1);
	while (nbr[i])
	{
		if (nbr[i] < "9223372036854775807"[i])
			return (0);
		if (nbr[i] > "9223372036854775807"[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_smaller_long_long(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-')
		nbr++;
	while (nbr[i] == '0')
		nbr++;
	if (ft_strlen(nbr) > 20)
		return (1);
	while (nbr[i])
	{
		if (nbr[i] < "9223372036854775808"[i])
			return (0);
		if (nbr[i] > "9223372036854775808"[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_is_numeric(char *arg, t_exec *exec)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			i++;
		if (!ft_isdigit(arg[i]))
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			free_exit(exec, 2, TRUE);
		}
		i++;
	}
	if ((i >= 19 && arg[0] != '-' && is_greater_long_long(arg))
		|| (i >= 19 && arg[0] == '-' && is_smaller_long_long(arg)))
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_exit(exec, 2, TRUE);
	}
	return (0);
}

int	check_exit_error(char **args, t_exec *exec)
{
	int	i;

	i = 1;
	(void)exec;
	while (args[i])
	{
		if (i == 2)
			return (ft_putstr_fd("bash: exit: too many arguments\n", 2), 1);
		if (check_is_numeric(args[i], exec))
			return (1);
		i++;
	}
	return (0);
}
