/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                     :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

//void function3(void *content)
//{
//	//char *str = malloc(sizeof(char) * 5);
//	//ft_strcpy(str, "test");
//	free(content);
//}
//int main()
//{
//	t_list *head;

//	head = ft_lstnew("head0");
//	head->next = ft_lstnew("head1");
//	head->next->next = ft_lstnew("head1");

//	printf("1 %s\n", (char *)head->content);
//	ft_lstiter(head, function1);
//	printf("1 %s\n", (char *)head->content);

//}