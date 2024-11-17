/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:26:06 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/24 14:25:03 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "stdbool.h"
#include "limits.h"

/*
typedef struct s_list
{
	struct s_element	*first;
}						t_list;
*/
typedef struct s_list
{
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list 	*prev;
	int					data;
	int					index;
	int					push_cost;
	bool				cheapest;
	bool				above_median;
} 	t_list;

//main
void	get_stack(char **argv, t_list **a);
void	fill_stack_a(t_list **a, int num, int index);
t_list	*initialisation ();

//checker
int		check_errors(char **argv);
int		ft_argv_is_integer(char **argv);
int		ft_argv_max_min(char **argv);
int		ft_duplicates(char **argv);

//rotate
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

//reverse_rotate
void	reverse_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

//swap
void	swap(t_list **a);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

//push
void	push(t_list *a, t_list *b, char c);

//utils
void	ft_insert(t_list *a, int num);
void	ft_delete(t_list *a);
void	print_list_ab(t_list *a, t_list *b);
void	print_list(t_list *a);
int		stack_len(t_list *stack);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);

//sorting_algo
bool	stack_sorted(t_list *stack);
void	sort_three(t_list **a);

#endif
