/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:08 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:35 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// void ft_del(void *content)
// {
// 	printf("%s\n", (char*)content);
// }

// int main(int argc, char const *argv[])
// {
// 	t_list *lst1 = ft_lstnew("salut1");
// 	t_list *lst2 = ft_lstnew("salut2");
// 	t_list *lst3 = ft_lstnew("salut3");
// 	t_list *lst4 = ft_lstnew("salut4");

// 	lst1->next = lst2;
// 	lst2->next = lst3;
// 	lst3->next = lst4;
// 	ft_lstiter(lst1, &ft_del);
// 	return (0);
// }