/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/09 01:03:04 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 0;

int	check_empty_line(char *rl_str)
{
	int	i;

	i = 0;
	while (rl_str[i])
	{
		if (!ft_isspace(rl_str[i]))
			return (0);
		i++;
	}
	free(rl_str);
	return (1);
}

int	parser(t_exec *exec, char *readline_str)
{
	exec->mal_lst = NULL;
	lstadd_back_malloc(exec, lstnew_malloc(readline_str));
	exec->lex_lst = lexer(readline_str, exec);
	if (check_error(exec->lex_lst))
	{
		free_lst_malloc(exec->mal_lst);
		return (1);
	}
	expander(exec);
	exec->tok_lst = get_token_lst(exec);
	return (0);
}

void	increment_shlvl(t_exec *exec)
{
	char	*shlvl_str;
	int		shlvl;

	shlvl_str = get_env_value("SHLVL", exec);
	shlvl = ft_atoi(shlvl_str);
	shlvl++;
	shlvl_str = ft_itoa(shlvl);
	change_env_value("SHLVL", shlvl_str, exec);
}

int	main(int argc, char **argv, char **env)
{
	t_exec	exec_struct;

	(void)argc;
	(void)argv;
	exec_struct.env_lst = get_env_lst(env);
	increment_shlvl(&exec_struct);
	while (1)
	{
		signal(SIGINT, sig_int_rl);
		signal(SIGQUIT, SIG_IGN);
		exec_struct.readline_str = readline("Minishell> ");
		if (!exec_struct.readline_str)
			break ;
		add_history(exec_struct.readline_str);
		if (check_empty_line(exec_struct.readline_str))
			continue ;
		if (parser(&exec_struct, exec_struct.readline_str))
			continue ;
		init_exec(&exec_struct);
		exec(&exec_struct);
		free_lst_malloc(exec_struct.mal_lst);
	}
	free_env_lst(exec_struct.env_lst);
	ft_putstr_fd("exit\n", 2);
}
