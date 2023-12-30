/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:40 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:39:27 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	push_node(t_element **src_node, t_element **dest_node,
	t_bool what_stack)
{
	t_element	*cheapest;

	index_assign(dest_node);
	cheapest = find_cheapest(*src_node);
	rotate_both(src_node, dest_node, cheapest);
	if (what_stack)
	{
		prepare_stack(src_node, cheapest, do_ra, do_rra);
		prepare_stack(dest_node, cheapest->target, do_rb, do_rrb);
	}
	else
	{
		prepare_stack(src_node, cheapest, do_rb, do_rrb);
		prepare_stack(dest_node, cheapest->target, do_ra, do_rra);
	}
	if (what_stack)
		do_pb(src_node, dest_node, PRINTBOOL_PS);
	else
		do_pa(src_node, dest_node, PRINTBOOL_PS);
}

/* prepare_stack:
*  rotate it untill it is on the top top position
*/

void	prepare_stack(t_element **stack, t_element *push_node,
		void (*rotate)(t_element **node, t_bool print),
		void (*rev_rotate)(t_element **target_stack, t_bool print))
{
	if (push_node->above_median == TRUE)
		while (push_node != *stack)
			rotate(stack, PRINTBOOL_PS);
	else
		while (push_node != *stack)
			rev_rotate(stack, PRINTBOOL_PS);
}

/* rotate_both:
*  rotates both when they are both above or below the median line
*  until one of them is on the top position
*/

void	rotate_both(t_element **src_node, t_element **dest_node,
	t_element *cheapest)
{
	t_bool	target_med;

	target_med = cheapest->target->above_median;
	if (cheapest->above_median == TRUE && target_med == TRUE)
		while (cheapest != *src_node && cheapest->target != *dest_node)
			do_rr(src_node, dest_node, PRINTBOOL_PS);
	else if (cheapest->above_median == FALSE && target_med == FALSE)
		while (cheapest != *src_node && cheapest->target != *dest_node)
			do_rrr(src_node, dest_node, PRINTBOOL_PS);
}

t_element	*find_cheapest(t_element *node)
{
	while (node)
	{
		if (node->cheapest == TRUE)
			return (node);
		node = node->element_down;
	}
	return (node);
}

//printf("-----B-->A---pre_rotate\n-----B\n");
//print_lst_debug(src_node);
//printf("-----A\n");
//printf("----------p2----------A\n");
//print_lst_debug(src_node);
//printf("----------p2----------B\n");
//print_lst_debug(dest_node);
// printf("In push_node 1\n");
// print_lst_debug(dest_node);