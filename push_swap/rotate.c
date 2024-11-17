/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:47:13 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/24 13:56:46 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_list **a)
{
	if (!*a)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	if (!*b)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	if (!*a && !*b)
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
