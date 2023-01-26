/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:23:19 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:24 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

//int main(int argc, char const *argv[])
//{
//	char array1[] = "salut1";
//	char array2[] = "salut2";
//	char arraylast[] = "Fin";

//	//t_list *lst1 = ft_lstnew(array1);
//	t_list *lst1 = NULL;
//	t_list *last = ft_lstnew(arraylast);
//	//lst1->next = ft_lstnew(array2);
//	ft_lstadd_back(&lst1, last);
//	t_list *result = ft_lstlast(lst1);
//	printf("%s", (char*)result->content);
//	return (0);
//}