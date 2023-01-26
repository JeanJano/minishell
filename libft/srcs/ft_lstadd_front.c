/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:32 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:27 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

//int main(int argc, char const *argv[])
//{
//	char array1[] = "salut1";
//	char array2[] = "salut2";

//	t_list *lst1 = ft_lstnew(array1);
//	t_list *lst2 = ft_lstnew(array2);
//	ft_lstadd_front(&lst1, lst2);
//	printf("%s ", (char*)lst2->content);
//	printf("%s", (char*)lst2->next->content);
//	return (0);
//}