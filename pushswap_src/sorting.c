/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:54 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:43:46 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <limits.h>

void	turk_algorith(t_element **node_a, t_element **node_b)
{
	do_pb(node_a, node_b, PRINTBOOL_PS);
	do_pb(node_a, node_b, PRINTBOOL_PS);
	while (ps_lstsize(node_a) > 3)
	{
		init_stack_a(node_a, node_b);
		push_node(node_a, node_b, 1);
	}
	if (ps_lstsize(node_a) == 3)
		sort_three_ascend(node_a);
	while (*node_b)
	{
		init_stack_b(node_b, node_a);
		push_node(node_b, node_a, 0);
	}
	while (find_smallest(*node_a) != *node_a)
	{
		if (find_smallest(*node_a)->above_median)
			do_ra(node_a, PRINTBOOL_PS);
		else
			do_rra(node_a, PRINTBOOL_PS);
	}
}

int	stack_sorted(t_element *node_a)
{
	int			i;
	t_element	*node_current;

	i = 0;
	node_current = node_a;
	while (i < ps_lstsize(&node_a) - 1)
	{
		if (node_current->value > node_current->element_down->value)
			return (0);
		i++;
		node_current = node_current->element_down;
	}
	return (1);
}

int	sort_list(t_element **t_elements_a)
{
	t_element	*node_b;

	node_b = NULL;
	if (!stack_sorted(*t_elements_a))
	{
		if (ps_lstsize(t_elements_a) == 2)
			do_sa(t_elements_a, PRINTBOOL_PS);
		else if (ps_lstsize(t_elements_a) == 3)
			sort_three_ascend(t_elements_a);
		else
			turk_algorith(t_elements_a, &node_b);
	}
	return (0);
}

//printf("smallest\t%d\n" , data.smallest);
//printf("biggest\t%d\n" , data.biggest);
//init_data(t_elements_a, &a_data, size);
//init_data(&node_b, &b_data, size);
//------
// printf("-----------------------A\n");
// print_lst_debug(node_a);
// printf("-----------------------B\n");
// print_lst_debug(node_b);