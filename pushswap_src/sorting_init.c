/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:49 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	init_stack_a(t_element **node_a, t_element **node_b)
{
	index_assign(node_a);
	index_assign(node_b);
	assign_targets_a(*node_a, *node_b);
	calc_cost_src_dst(node_a, node_b);
	assign_cheapest(*node_a);
}

void	init_stack_b(t_element **node_b, t_element **node_a)
{
	index_assign(node_a);
	index_assign(node_b);
	assign_targets_b(*node_b, *node_a);
	calc_cost_src_dst(node_b, node_a);
	assign_cheapest(*node_b);
}

void	index_assign(t_element **node)
{
	t_element	*current;
	int			i;
	int			median;

	if (*node == NULL)
		return ;
	i = 0;
	current = *node;
	median = ps_lstsize(node) / 2;
	while (current != NULL)
	{
		current->index = i;
		if (i <= median)
			current->above_median = TRUE;
		else
			current->above_median = FALSE;
		current = current->element_down;
		i++;
	}
}

void	calc_cost_src_dst(t_element **src_node, t_element **dst_node)
{
	t_element	*current_src;

	current_src = *src_node;
	while (current_src)
	{
		if (current_src->index <= ps_lstsize(src_node) / 2)
			current_src->cost = current_src->index;
		else
			current_src->cost = ps_lstsize(src_node) - current_src->index;
		if (current_src->target->index <= ps_lstsize(dst_node) / 2)
			current_src->cost += current_src->target->index;
		else
			current_src->cost += ps_lstsize(dst_node)
				- current_src->target->index;
		current_src = current_src->element_down;
	}
}

void	assign_cheapest(t_element *node_a)
{
	t_element	*cheapest;

	cheapest = node_a;
	while (node_a)
	{
		if (node_a->cost < cheapest->cost)
			cheapest = node_a;
		node_a = node_a->element_down;
	}
	cheapest->cheapest = TRUE;
}
