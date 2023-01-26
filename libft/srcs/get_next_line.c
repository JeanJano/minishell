/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:36:19 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:45:27 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_result(t_list_char *lst)
{
	int			i;
	int			size;
	char		*result;
	t_list_char	*tmp;

	i = 0;
	size = ft_lstsize_char(lst);
	if (size == 0)
	{
		return (NULL);
	}
	result = malloc((size + 1) * sizeof(char));
	while (lst)
	{
		tmp = lst->next;
		result[i] = lst->content;
		free(lst);
		i++;
		lst = tmp;
	}
	result[i] = 0;
	return (result);
}

int	get_static_buffer(char *buffer, t_list_char **result)
{
	int	i;

	i = 0;
	while (buffer[i++] && buffer[i] == 1 && i < BUFFER_SIZE)
		if (buffer[i] == '\n')
			break ;
	while (buffer[i] && i < BUFFER_SIZE)
	{
		if (!result)
			*result = ft_lstnew_char(buffer[i]);
		else
			ft_lstadd_back_char(result, ft_lstnew_char(buffer[i]));
		if (buffer[i] == '\n')
		{
			buffer[i] = 1;
			return (1);
		}
		buffer[i] = 1;
		i++;
	}
	return (0);
}

int	get_buffer(int fd, char *buffer, t_list_char **result)
{
	int	i;

	i = 0;
	while (read(fd, buffer, BUFFER_SIZE))
	{
		while (buffer[i] && i < BUFFER_SIZE)
		{
			if (!result)
				*result = ft_lstnew_char(buffer[i]);
			else
				ft_lstadd_back_char(result, ft_lstnew_char(buffer[i]));
			if (buffer[i] == '\n')
			{
				buffer[i] = 1;
				return (1);
			}
			buffer[i] = 1;
			i++;
		}
		ft_bzero(buffer, BUFFER_SIZE);
		i = 0;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFFER_SIZE];
	t_list_char	*result;
	char		*result_str;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	result = NULL;
	if (get_static_buffer(buffer[fd], &result))
		return (get_result(result));
	ft_bzero(buffer[fd], BUFFER_SIZE);
	if (get_buffer(fd, buffer[fd], &result))
		return (get_result(result));
	result_str = get_result(result);
	return (result_str);
}

// int	main(void)
// {
// 	int fd;
// 	fd = open("text", O_RDONLY);
// 	// fd = 0;
// 	char *result;
// 	result = get_next_line(fd);
// 	printf("%s", result);

// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// }