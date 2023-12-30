/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:51 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_element	*find_biggest(t_element *node)
{
	t_element	*biggest;

	if (NULL == node)
		return (NULL);
	biggest = node;
	while (node)
	{
		if (node->value > biggest->value)
			biggest = node;
		node = node->element_down;
	}
	return (biggest);
}

t_element	*find_smallest(t_element *node)
{
	t_element	*biggest;

	if (NULL == node)
		return (NULL);
	biggest = node;
	while (node)
	{
		if (node->value < biggest->value)
			biggest = node;
		node = node->element_down;
	}
	return (biggest);
}

void	sort_three_descend(t_element **node_a)
{
	t_element	*smallest_node;

	smallest_node = find_smallest(*node_a);
	if (*node_a == smallest_node)
		do_ra(node_a, PRINTBOOL_PS);
	else if ((*node_a)->element_down == smallest_node)
		do_rra(node_a, PRINTBOOL_PS);
	if ((*node_a)->value < (*node_a)->element_down->value)
		do_sa(node_a, PRINTBOOL_PS);
}

void	sort_three_ascend(t_element **node_a)
{
	t_element	*highest_node;

	highest_node = find_biggest(*node_a);
	if (*node_a == highest_node)
		do_ra(node_a, PRINTBOOL_PS);
	else if ((*node_a)->element_down == highest_node)
		do_rra(node_a, PRINTBOOL_PS);
	if ((*node_a)->value > (*node_a)->element_down->value)
		do_sa(node_a, PRINTBOOL_PS);
}
