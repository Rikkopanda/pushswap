/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                :+:         :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//geef t_list*  van eerste node(lst)
//vind laatse, next hiervan zet new erin
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

//int main()
//{
//	//t_list **listarray = malloc(sizeof(*t_list) * 4);
//	//listarray[]
//	t_list *lst;
//	lst = ft_lstnew("test1");
//	t_list *new = ft_lstnew("send to back of the line");
//	lst = ft_lstnew("head0");
//	(*lst).next = ft_lstnew("1");
//	(*lst).next->next = ft_lstnew("2");
//	(*lst).next->next->next = ft_lstnew("3");
//	(*lst).next->next->next->next = NULL;
//	printf("last %p\n", ft_lstlast(lst));
//	printf("new %p\n",new);
//	ft_lstadd_back(&lst, new);
//	printf("last %p\n", ft_lstlast(lst));
//	printf("new %p\n",new);
//	free(new->next);
//	free(new);
//}// memo leak