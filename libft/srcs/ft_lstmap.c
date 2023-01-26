/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:22:42 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:41 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	result = NULL;
	if (!lst)
		del(lst);
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			del(temp);
			free(temp);
		}
		if (!result)
			result = temp;
		else
			ft_lstadd_back(&result, temp);
		lst = lst->next;
	}
	return (result);
}

//void	*ft_map(void *ct)
//{
//	int i;
//	void	*c;
//	char	*pouet;

//	c = ct;
//	i = -1;
//	pouet = (char *)c;
//	while (pouet[++i])
//		if (pouet[i] == 'o')
//			pouet[i] = 'a';
//	return (c);
//}

//void ft_del(void *content)
//{
//	printf("%s\n", (char*)content);
//}

//int main(void)
//{
//	t_list		*elem;
//	t_list		*elem2;
//	t_list		*elem3;
//	t_list		*elem4;
//	t_list		*list;
//	char		str[] = "lorem";
//	char		str2[] = "ipsum";
//	char		str3[] = "dolor";
//	char		str4[] = "sit";

//	elem = ft_lstnew(str);
//	elem2 = ft_lstnew(str2);
//	elem3 = ft_lstnew(str3);
//	elem4 = ft_lstnew(str4);

//	elem->next = elem2;
//	elem2->next = elem3;
//	elem3->next = elem4;
//	list = ft_lstmap(elem, &ft_map, &ft_del);
//	while (list)
//	{
//		printf("%s\n", (char*)list->content);
//		list = list->next;
//	}
//}