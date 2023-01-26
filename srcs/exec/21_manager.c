/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:46:29 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:31 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_lst_size(t_env_lst *env_lst)
{
	int	i;

	i = 0;
	while (env_lst)
	{
		i++;
		env_lst = env_lst->next;
	}
	return (i);
}

char	**env_lst_to_array(t_env_lst *env_lst, t_exec *exec)
{
	t_env_lst	*head;
	char		**result;
	char		*content;
	int			i;

	i = get_env_lst_size(env_lst);
	head = env_lst;
	result = malloc((i + 1) * sizeof(char *));
	lstadd_back_malloc(exec, lstnew_malloc(result));
	i = 0;
	while (head)
	{
		content = ft_strjoin(head->name, "=");
		lstadd_back_malloc(exec, lstnew_malloc(content));
		content = ft_strjoin(content, head->value);
		lstadd_back_malloc(exec, lstnew_malloc(content));
		result[i++] = content;
		head = head->next;
	}
	result[i] = NULL;
	return (result);
}

void	command(t_exec *exec)
{
	char	**env;
	char	**args;
	char	*path;

	env = env_lst_to_array(exec->env_lst, exec);
	args = lst_to_str_array(exec->tok_lst->args, exec);
	if (!is_built_in(args[0]))
		path = get_right_path(get_env_value("PATH", exec),
				exec->tok_lst->args, exec);
	if (is_built_in(args[0]))
		free_exit(exec, exec_built_in(exec), TRUE);
	close_fds(2, exec->pipe_fd[0], exec->pipe_fd[1]);
	execve(path, args, env);
}

void	exec_token(t_exec *exec, int i)
{
	int	output_fd;
	int	input_fd;

	output_fd = exec->tok_lst->output_fd;
	input_fd = exec->tok_lst->input_fd;
	if (check_infile(exec->tok_lst) || check_outfile(exec->tok_lst))
		free_exit(exec, g_status, TRUE);
	if (i != exec->nb_command - 1)
		dup2(exec->pipe_fd[1], STDOUT_FILENO);
	if (output_fd == REDIR_OUT)
		redir_out(exec->tok_lst);
	else if (output_fd == APP_OUT)
		append(exec->tok_lst);
	if (input_fd == REDIR_IN)
		redir_in(exec->tok_lst);
	else if (input_fd == HERE_DOC)
		here_doc(exec->tok_lst);
	if (exec->tok_lst->args != NULL)
		command(exec);
	free_exit(exec, 0, TRUE);
}
