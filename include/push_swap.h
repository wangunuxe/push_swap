/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jili <jili@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:28:06 by jili              #+#    #+#             */
/*   Updated: 2025/03/28 15:27:16 by jili             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include "../Libft/libft.h"

typedef struct s_stack_node
{
	long					number;
	int						push_cost;
	bool					up;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*pre;
	struct s_stack_node		*next;
}							t_stack_node;

void			pa(t_stack_node **b_head, t_stack_node **a_head, bool print);
void			pb(t_stack_node **a_head, t_stack_node **b_head, bool print);
void			rra(t_stack_node **a_head, bool print);
void			rrb(t_stack_node **b_head, bool print);
void			rrr(t_stack_node **a_head, t_stack_node **b_head, bool print);
void			ra(t_stack_node **a_head, bool print);
void			rb(t_stack_node **b_head, bool print);
void			rr(t_stack_node **a_head, t_stack_node **b_head, bool print);
void			sa(t_stack_node **a_head, bool print);
void			sb(t_stack_node **b_head, bool print);
void			ss(t_stack_node **a_head, t_stack_node **b_head, bool printf);
void			ft_swap(t_stack_node **pp_head);

int				error_syntax(char *str);
int				error_duplicate_bigger_smaller(t_stack_node **pp_head, long n);
void			free_stack(t_stack_node **pp_head);
void			printerror_free(t_stack_node **pp_head);

void			init_stack_a(t_stack_node	**pp_head, char **argv);
int				len_of_word(char *str, char separator);
int				num_of_words(char *str, char separator);
char			*get_word(char *str, char separator);
void			free_words(char **arr, int index_current_word);
int				fill_split_array(char *str, char sep, char **arr);
char			**ft_split_new(char *str, char separator);

int				steps_move_to_top(t_stack_node **pp_head, \
				t_stack_node *required_node);
void			algori_sort_stacks(t_stack_node **pp_head_a, \
				t_stack_node **pp_head_b);
t_stack_node	*extract_cheapest_node(t_stack_node **pp_head);
int				count_forward_steps(t_stack_node **pp_head, \
				t_stack_node *required_node);
int				count_backforward_steps(t_stack_node **pp_head, \
				t_stack_node *required_node);
void			move_to_top(t_stack_node **pp_head, \
				t_stack_node *required_node, char stack_name);
void			rotate_to_cheapest(t_stack_node **pp_head_a, \
				t_stack_node **pp_head_b, t_stack_node	*cheapest);
void			rev_rotate_to_cheapest(t_stack_node **pp_head_a, \
				t_stack_node **pp_head_b, t_stack_node	*cheapest);
void			move_a_to_b(t_stack_node **pp_head_a, t_stack_node **pp_head_b);
void			move_b_to_a(t_stack_node **pp_head_a, t_stack_node **pp_head_b);
void			min_to_top(t_stack_node **pp_head);
void			find_target_of_a(t_stack_node *head_a, t_stack_node *head_b);
void			push_cost(t_stack_node *head_a, t_stack_node *head_b);
void			min_to_top(t_stack_node **pp_head);

void			init_node_a(t_stack_node *head_a, t_stack_node *head_b);
void			init_node_b(t_stack_node *head_b, t_stack_node *head_a);

t_stack_node	*find_last(t_stack_node *p_head);
t_stack_node	*find_min_node(t_stack_node *p_head);
t_stack_node	*find_max_node(t_stack_node *p_head);
int				stack_lenth(t_stack_node *p_head);

#endif
