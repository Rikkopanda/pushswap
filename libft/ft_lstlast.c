/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
//int main()
//{
//	t_list *head;
//	t_list *last;
//	int i;
//	int size;
//	i = 1;
//	head = ft_lstnew("head0");
//	(*head).next = ft_lstnew("1");
//	(*head).next->next = ft_lstnew("2");
//	(*head).next->next->next = ft_lstnew("3");
//	(*head).next->next->next->next = NULL;
//	//printf("%s", (char *)(*head).next->next->next->content);
//	last = ft_lstlast(head);
//	//printf("%s", (char *)last->content);
//	//free(ft_lstlast(head));
//}//memo leaaak