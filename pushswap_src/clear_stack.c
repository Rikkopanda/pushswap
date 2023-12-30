/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:30 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	ps_lstclear(t_element **t_element_a)
{
	t_element	*tmp;

	if (!t_element_a || !*t_element_a)
		return ;
	free((*t_element_a)->stack_info);
	(*t_element_a)->stack_info = 0;
	if (t_element_a)
	{
		while ((*t_element_a)->element_down != NULL)
		{
			tmp = (*t_element_a)->element_down;
			ps_lstdelone(*t_element_a);
			*t_element_a = tmp;
		}
		ps_lstdelone(*t_element_a);
	}
	t_element_a = 0;
}
//printf("%d address = %p FREED \t\tnext = %p\n ", 
//(*t_element_a)->value, *t_element_a, ((*t_element_a)->element_down));

void	ps_lstdelone(t_element *t_element_a)
{
	if (!t_element_a)
		return ;
	free(t_element_a);
	t_element_a = 0;
}
