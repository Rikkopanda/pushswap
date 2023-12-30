/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                   :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
	lst = 0;
}

//int main()
//{
//	t_list *head;

//	head = ft_lstnew("head0");
//	printf("%s\n", (char *)head->content);
//	ft_lstdelone(head, &delete);
//	//printf("%s\n", (char *)head->content);
//	//printf("%s\n", (char *)head->content);
//}