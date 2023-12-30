/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:24 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

static void	swap(t_element **stack)
{
	t_element	*tmp;

	tmp = *stack;
	*stack = (*stack)->element_down;
	if (ps_lstsize(stack) > 1)
		tmp->element_down = (*stack)->element_down;
	else
		tmp->element_down = NULL;
	(*stack)->element_down = tmp;
}

//use printdebug function for clarifying

/* do_sa:
*	Swaps the top t_element of stack a with second.
*	Prints "sa" to the standard output.
*/

void	do_sa(t_element **stack_a, t_bool print)
{
	swap(stack_a);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_element **stack_b, t_bool print)
{
	swap(stack_b);
	(*stack_b)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("sb\n", 1);
}

void	do_ss(t_element **stack_a, t_element **stack_b, t_bool print)
{
	swap(stack_a);
	swap(stack_b);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("ss\n", 1);
}
