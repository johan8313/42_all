/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:21:45 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/24 13:23:41 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if(!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_list **a)
{
	t_list	*biggest_element;

	biggest_element = find_max(*a);
	print_list(biggest_element);
	if (biggest_element == *a)
	{
		rotate(*a);
		//print_list(*a);
	}
	else if ((*a)->next == biggest_element)
		reverse_rotate(*a);
	if ((*a)->data > (*a)->next->data)
		swap(*a);
}



