/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:21 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/* rotate:
*	The top t_element of the stack is sent to the bottom.
*/
static void	rotate(t_element **stack)
{
	t_element	*tmp;

	if (ps_lstsize(stack) < 1 || *stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->element_down;
	tmp->element_down = NULL;
	tmp->up = ps_lstlast(*stack);
	ps_lstlast(*stack)->element_down = tmp;
}

/* do_ra:
*	Sends the top t_element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_ra(t_element **stack_a, t_bool print)
{
	rotate(stack_a);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/* do_rb:
*	Sends the top t_element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rb(t_element **stack_b, t_bool print)
{
	rotate(stack_b);
	(*stack_b)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("rb\n", 1);
}

/* do_rr:
*	Sends the top t_element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	do_rr(t_element **stack_a, t_element **stack_b, t_bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	(*stack_b)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("rr\n", 1);
}
