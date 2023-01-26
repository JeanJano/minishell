/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvage <jsauvage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:07:33 by jsauvage          #+#    #+#             */
/*   Updated: 2023/01/05 17:35:29 by jsauvage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_right_path(char *path, t_array_lst *cmd, t_exec *exec)
{
	char	**split_path;
	int		i;
	char	*res;
	char	*tmp;

	if (ft_strlen(cmd->content) == 0)
		free_exit(exec, 127, TRUE);
	res = ft_abs_path(cmd->content, exec);
	if (res)
		return (res);
	if (!path)
		free_exit(exec, 127, TRUE);
	split_path = ft_split(path, ':');
	i = -1;
	while (split_path[++i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		res = ft_strjoin(tmp, cmd->content);
		free(tmp);
		if (access(res, X_OK) == 0)
			return (ft_strdup(res));
		free(res);
	}
	ft_null_access(split_path, exec);
	return (NULL);
}
