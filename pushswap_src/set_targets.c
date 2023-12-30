/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:46 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	assign_targets_a(t_element *node_a, t_element *node_b)
{
	t_element	*target_node;
	t_element	*current_b;
	long		closest_smaller;

	while (node_a)
	{
		closest_smaller = (long)INT_MIN - 1;
		current_b = node_b;
		while (current_b)
		{
			if (node_a->value > current_b->value
				&& closest_smaller < current_b->value)
			{
				closest_smaller = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->element_down;
		}
		if (closest_smaller == (long)INT_MIN - 1)
			node_a->target = find_biggest(node_b);
		else
			node_a->target = target_node;
		node_a = node_a->element_down;
	}
}

void	assign_targets_b(t_element *node_b, t_element *node_a)
{
	t_element		*target_node;
	t_element		*current_a;
	long			closest_bigger;

	while (node_b)
	{
		closest_bigger = (long)INT_MAX + 1;
		current_a = node_a;
		while (current_a)
		{
			if (node_b->value < current_a->value
				&& closest_bigger > current_a->value)
			{
				closest_bigger = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->element_down;
		}
		if (closest_bigger == (long)INT_MAX + 1)
			node_b->target = find_smallest(node_a);
		else
			node_b->target = target_node;
		node_b = node_b->element_down;
	}
}
