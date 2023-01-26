/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by rvincent          #+#    #+#             */
/*   Updated: 2023/01/09 01:03:01 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **args, t_exec *exec)
{
	int	exit_status;
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (check_exit_error(args, exec))
		return (1);
	if (i == 1)
	{
		ft_putstr_fd("exit\n", 2);
		free_exit(exec, g_status, TRUE);
	}
	exit_status = ft_atoi(args[1]) % 256;
	free_exit(exec, exit_status, TRUE);
	return (0);
}

int	ft_pwd(t_exec *exec)
{
	char	buff[PATH_MAX];
	char	*path;

	path = get_env_value("PWD", exec);
	if (path)
		return (printf("%s\n", path), 0);
	path = getcwd(buff, PATH_MAX);
	if (!path)
		return (perror("pwd"), 1);
	printf("%s\n", path);
	return (0);
}

int	ft_echo(char **cmd)
{
	int		i;
	char	*nl;
	int		j;

	i = 1;
	nl = "\n";
	while (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		j = 1;
		while (cmd[i][j] == 'n')
			j++;
		if (!cmd[i][j])
		{
			nl = "";
			i++;
		}
		else
			break ;
	}
	if (cmd[i])
		printf("%s", cmd[i++]);
	while (cmd[i])
		printf(" %s", cmd[i++]);
	printf("%s", nl);
	return (0);
}

int	ft_cd(char **path, t_exec *exec)
{
	char	buff[PATH_MAX];
	char	*old_pwd;
	char	*new_pwd;
	int		chdir_value;

	if (!path[1])
		chdir_value = chdir(get_env_value("HOME", exec)) < 0;
	else if (!path[2])
	{
		if (ft_strmatch(path[1], "-"))
			chdir_value = chdir(get_env_value("OLDPWD", exec));
		else
			chdir_value = chdir(path[1]);
	}
	else
		return (ft_putstr_fd("cd: too many arguments\n", 2), 1);
	if (chdir_value == -1)
		return (perror("cd"), 1);
	new_pwd = ft_strdup(getcwd(buff, PATH_MAX));
	old_pwd = ft_strdup(get_env_value("PWD", exec));
	change_env_value("OLDPWD", old_pwd, exec);
	change_env_value("PWD", new_pwd, exec);
	return (0);
}
