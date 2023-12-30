/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		count;

	if (lst == NULL)
		return (0);
	current = lst;
	count = 1;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
//int main()
//{
//	t_list *head;
//	int i;
//	int size;
//	i = 1;
//	head = ft_lstnew("head0");
//	(*head).next = ft_lstnew("1");
//	(*head).next->next = ft_lstnew("2");
//	(*head).next->next->next = ft_lstnew("3");
//	(*head).next->next->next->next = NULL;
//	//printf("%s", (char *)(*head).next->next->next->content);
//	size = ft_lstsize(head);
//	printf("%d", size);	
//}