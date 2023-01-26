/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:22:35 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/11 15:16:43 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (0);
	result->content = content;
	result->next = NULL;
	return (result);
}

// int main(int argc, char const *argv[])
// {
// 	t_list *lst1 = ft_lstnew("salut");
// 	lst1->next = ft_lstnew("salut2");
// 	while (lst1)
// 	{
// 		printf("%s\n", (char *)lst1->content);
// 		lst1 = lst1->next;
// 	}
// 	return (0);
// }
