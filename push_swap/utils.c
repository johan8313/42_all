/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:29:06 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/25 09:13:19 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_ab(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*current_b;

	current = a;
	current_b = b;
	while (current != NULL)
	{
		ft_printf("%d ", current->data);

		if (current_b == NULL)
			ft_printf("\n");
		while (current_b != NULL)
		{
			ft_printf("%d\n", current_b->data);
			current_b = current_b->next;
		}
		current = current->next;
	}
	ft_printf("- -\na b\n");
}

void	print_list(t_list *a)
{
	t_list	*current;


	current = a;

	while (current != NULL)
	{
		ft_printf("%d\n", current->data);
		current = current->next;
	}
	ft_printf("-\na\n");
}

int	stack_len(t_list *stack)
{
	int	len;

	if(!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_list	*find_min(t_list *stack)
{
	long	min;
	t_list	*min_element;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	min_element = NULL;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_element = stack;
		}
		stack = stack->next;
	}
	return (min_element);
}

t_list	*find_max(t_list *stack)
{
	long	max;
	t_list	*max_element;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_element = stack;
		}
		stack = stack->next;
	}
	//ft_printf("max: %d", max_element->data);
	return (max_element);
}
