/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                    :+:         :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:43:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/15 12:43:34 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define _DEBUG
//#define _CRTDBG_MAP_ALLOC
//#define _CRTDBG_MAP_ALLOC_NEW
//#include <crtdbg.h>
//#include <assert.h>
//#include <stdlib.h>

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
	lst = 0;
}
//int main()
//{
//	//_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
//	//t_list *head;
//    //int* x = (int*)malloc(sizeof(int));
//    //*x = 7;
//    //printf("%d\n", *x);
//    //x = (int*)calloc(3, sizeof(int));
//    //x[0] = 7;
//    //x[1] = 77;
//    //x[2] = 777;
//    //printf("%d %d %d\n", x[0], x[1], x[2]);
//	//head = ft_lstnew("head0");
//	//printf("1 %s\n", (char *)head->content);
//	//lst_clear(&head, &delete);//crashes now
//	////printf("2 \n" );
//	//printf("3 \n" );
//	//_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
//	//_CrtDumpMemoryLeaks();
//}