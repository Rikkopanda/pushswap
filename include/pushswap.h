/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:31:56 by rverhoev          #+#    #+#             */
/*   Updated: 2023/12/20 16:43:53 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

# define PRINTBOOL_CKR 0
# define PRINTBOOL_PS 1
# define FALSE 0 
# define TRUE 1

typedef int	t_bool;

typedef struct s_stack
{
	struct s_stack	*up;
	struct s_stack	*element_down;
	struct s_stack	*target;
	t_bool			cheapest;
	t_bool			above_median;
	int				index;
	int				value;
	int				cost;
	t_bool			minimum;
	t_bool			maximum;
	struct s_data	*stack_info;
}	t_element;

typedef struct s_data
{
	int	*stack_arr;
	int	last_val;
	int	live_size;
	int	ini_size_a;
	int	smallest;
	int	biggest;
	int	nbr_of_instructs;
}	t_info;

//--------------------------------algoritihm--------------------------
//parse argv
int				check_duplicates(char **argv);
int				check_chars(char **argv);
int				check_input(char **argv);

//make stack_a
int				fill_list(t_element **t_elementnode_a, char **argv, int argc);
struct s_stack	*ps_lstnew(int content, t_info *stack_data);
void			ps_lstadd_back(t_element **lst, struct s_stack *new);
struct s_stack	*ps_lstlast(struct s_stack *lst);
struct s_stack	*ps_second_lstlast(struct s_stack *lst);

//clear list
void			ps_lstclear(t_element **t_element_a);
void			ps_lstdelone(t_element *t_element_a);

//general_tools
int				ps_lstsize(t_element **t_elements);
int				chr_arr_size(char **arr);
void			free_chrarr(char **arr);
void			print_data_stack(t_info *data);
void			ps_lstadd_front(t_element **lst, struct s_stack *new);
void			free_argv(int malloced, char **argv);

//--------------------------------algoritihm--------------------------
int				sort_list(t_element **t_elements_a);
void			turk_algorith(t_element **node_a, t_element **node_b);

//sorting_tools
void			sort_three_ascend(t_element **node_a);
void			sort_three_descend(t_element **node_a);
t_element		*find_biggest(t_element *node);
t_element		*find_smallest(t_element *node);
int				stack_sorted(t_element *node_a);

//init_stacks
void			init_stack_a(t_element **node_a, t_element **node_b);
void			init_stack_b(t_element **node_b, t_element **node_a);
void			index_assign(t_element **node);
void			calc_cost_src_dst(t_element **node_a, t_element **node_b);
void			assign_cheapest(t_element *node_a);

//set targets
void			assign_targets_a(t_element *node_a, t_element *node_b);
void			assign_targets_b(t_element *node_a, t_element *node_b);

//push_nodes
void			push_node(t_element **src_node, t_element **dest_node,
					t_bool what_stack);
void			prepare_stack(t_element **stack, t_element *push_node,
					void (*rotate)(t_element **node, t_bool print),
					void (*rev_rotate)(t_element **target_stack, t_bool print));
void			rotate_both(t_element **src_node, t_element **dest_node,
					t_element *cheapest);
t_element		*find_cheapest(t_element *node);

//--------------------------------commands--------------------------
//push
void			do_pa(t_element **src_stack, t_element **dst_stack,
					t_bool print);
void			do_pb(t_element **src_stack, t_element **dst_stack,
					t_bool print);

// rotate
void			do_rr(t_element **stack_a, t_element **stack_b, t_bool print);
void			do_ra(t_element **stack_a, t_bool print);
void			do_rb(t_element **stack_b, t_bool print);

// reverse rotate
void			do_rra(t_element **stack_a, t_bool print);
void			do_rrb(t_element **stack_b, t_bool print);
void			do_rrr(t_element **stack_a, t_element **stack_b, t_bool print);

//switch
void			do_sa(t_element **stack_a, t_bool print);
void			do_sb(t_element **stack_b, t_bool print);
void			do_ss(t_element **stack_a, t_element **stack_b, t_bool print);

//// debug
//void	print_lst(t_element **t_elements);
//void	print_lst_debug(t_element **t_elements);

#endif
