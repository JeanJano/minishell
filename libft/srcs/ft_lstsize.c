/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:22:24 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:46 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

//int main(int argc, char const *argv[])
//{
//	char array1[] = "salut1";
//	char array2[] = "salut2";

//	t_list *lst1 = ft_lstnew(array1);
//	t_list *lst2 = ft_lstnew(array2);
//	ft_lstadd_front(&lst1, lst2);
//	ft_lstsize(lst2);
//	//printf("%s", (char*)lst2->next->content);
//	return (0);
//}