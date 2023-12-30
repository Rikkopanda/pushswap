/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                      :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if (!rtn)
		return (NULL);
	(*rtn).content = content;
	(*rtn).next = NULL;
	return (rtn);
}
//int main()
//{
//	t_list *head;
//	int i;
//	i = 1;
//	head = ft_lstnew("head0");
//	(*head).next = ft_lstnew("1");
//	(*head).next->next = ft_lstnew("2");
//	(*head).next->next->next = ft_lstnew("3");
//	(*head).next->next->next->next = NULL;
//	printf("%s", (*head).next->next->next->content);
//}