/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                      :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//cc ft_lstmap.c ft_lstnew.c ft_delete.c 
//ft_strcpy.c ft_lstclear.c ft_lstdelone.c 
//ft_lstadd_back.c ft_memcpy.c ft_lstlast.c ft_strlen.c
//static void	*hmmmmm(t_list *lst, t_list *lst2, void (*del)(void *))
//{
//}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*made_content;

	if (!f || !lst || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		made_content = f(lst->content);
		new_node = ft_lstnew(made_content);
		if (!new_node)
		{
			del(made_content);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
//printf("content old %ld", (long int)lst->content);
//lst->content = made_content;
//printf("content new %ld", (long int)new_list->content);
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
//{
//	t_list	*new_list;
//	t_list	*new_node;
//	void	*set;

//	if (!lst || !f || !del)
//		return (NULL);
//	new_list = NULL;
//	while (lst)
//	{
//		set = f(lst->content);
//		new_node = ft_lstnew(set);
//		if (!new_node)
//		{
//			del(set);
//			ft_lstclear(&new_list, (*del));
//			return (new_list);
//		}
//		ft_lstadd_back(&new_list, new_node);
//		lst = lst->next;
//	}
//	return (new_list);
//}
//printf("1 %s\n", (char *)lst->content);
//static void *function1(void *content)
//{
//	char str[] = "test\0";
//	content = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
//	ft_memcpy(content, str, 6);
//	return (content);
//}
//int main()
//{
//	t_list *head;
//	t_list *lsthead2;
//	head = ft_lstnew("head0");
//	head->next = ft_lstnew("head1");
//	head->next->next = ft_lstnew("head1");
//	head->next->next->next = NULL;
//	printf("before %s\n", (char *)head->content);
//	lsthead2 = ft_lstmap(head, &function1, hmmmmm);
//	printf("after %s\n", (char *)lsthead2->content);
////	ft_lstclear(&lsthead2, ft_delete);
////	ft_lstclear(&head, ft_delete);
//}