/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 07:52:15 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:03:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

/* rotate:
*	The top t_element of the stack is sent to the bottom.
*/
static void	reverse_rotate(t_element **stack)
{
	t_element	*last;
	t_element	*second_last;

	if (!*stack || !(*stack)->element_down)
		return ;
	last = ps_lstlast(*stack);
	second_last = ps_second_lstlast(*stack);
	second_last->element_down = NULL;
	last->element_down = *stack;
	*stack = last;
}

//last->up->element_down = NULL; 		//Assign to the `next` -
//-attribute of the node before itself, `NULL` effectively setting-
//-it as the current last node
//last->element_down = *stack; 			//Assign to its own `next`-
//- attribute as the top node of the stack
//last->up = NULL; 						//Detach itself from the node before it
//*stack = last;  						//Complete appending itself-
//- to the top of the stack, and now holds the pointer to the top node
//last->element_down->up = last;		//Update the current-
//-last node of the stack

/* do_rra:
*	Sends the top t_element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	do_rra(t_element **stack_a, t_bool print)
{
	reverse_rotate(stack_a);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/* do_rrb:
*	Sends the top t_element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	do_rrb(t_element **stack_b, t_bool print)
{
	reverse_rotate(stack_b);
	(*stack_b)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/* do_rrr:
*	Sends the top t_element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	do_rrr(t_element **stack_a, t_element **stack_b, t_bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	(*stack_a)->stack_info->nbr_of_instructs++;
	if (print)
		ft_putstr_fd("rrr\n", 1);
}
