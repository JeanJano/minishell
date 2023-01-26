/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:47:06 by rvincent          #+#    #+#             */
/*   Updated: 2022/06/05 15:28:51 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct t_node
{
	char			content;
	struct t_node	*next;
}					t_list_char;

t_list_char			*ft_lstnew_char(char content);
void				ft_lstadd_back_char(t_list_char **lst, t_list_char *new);
int					ft_lstsize_char(t_list_char *lst);
char				*get_next_line(int fd);

#endif