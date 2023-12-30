/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//geef t_list*  van eerste node(lst)
//next van nieuwe wordt de eeste(lst)
//addres van eerste wordt de nieuwe
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}

//int main()
//{
//	//t_list **listarray = malloc(sizeof(*t_list) * 4);
//	//listarray[]
//	t_list *lst;
//	lst = ft_lstnew("test1");
//	lst->next = NULL; //pointer en accesser
//	t_list *new = ft_lstnew("asshole jumped in front of line");
//	printf("next new %p\n",(new)->next);
//	printf("1st %p\n",lst);
//	printf("new %p\n\n",new);
//	ft_lstadd_front(&lst, new);
//	//printf("%s\n",(char *)(lst)->content);
//	//printf("%s\n", (char *)(lst)->next->content);
//	printf("next new %p\n",(new)->next);
//	printf("1st %p\n",lst);
//	printf("new %p\n",new);
//	free(new->next);
//	free(new);
//}