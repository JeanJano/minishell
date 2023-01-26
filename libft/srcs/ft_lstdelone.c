/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:24:05 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:32 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

// void	ft_del(void *content)
// {
// 	printf("%s supprime", (char *)content);
// }

// int main(int argc, char const *argv[])
// {
// 	char array1[] = "salut1";

// 	t_list *lst1 = ft_lstnew(array1);
// 	ft_lstdelone(lst1, &ft_del);
// 	return (0);
// }