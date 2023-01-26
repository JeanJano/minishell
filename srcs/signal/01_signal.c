/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:45:32 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_process(int sig_num)
{
	if (sig_num == SIGQUIT)
		g_status = 131;
	else if (sig_num == SIGINT)
		g_status = 130;
}

void	sig_int_rl(int sig_num)
{
	if (sig_num == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_status = 130;
	}
}

static void	handle_signal_hd(int signal, siginfo_t *info, void *context)
{
	int	fd;

	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		fd = open("/dev/null", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		ft_putstr_fd("\n", 1);
		g_status = 777;
	}
	if (signal == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 0);
}

void	signal_manager_hd(void)
{
	struct sigaction	s_sig;

	s_sig.sa_sigaction = handle_signal_hd;
	s_sig.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sig.sa_mask);
	sigaction(SIGINT, &s_sig, 0);
	sigaction(SIGQUIT, &s_sig, 0);
}
