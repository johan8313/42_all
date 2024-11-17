/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:21:06 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/25 09:13:23 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *a, t_list *b, char c)
{
	if (c == 'a')
	{
		ft_insert(a, b->data);
		ft_delete(b);
		ft_printf("pa\n");
	}
	if (c == 'b')
	{
		ft_printf("pb\n");
		print_list(a);
		ft_insert(b, a->data);
		ft_delete(a);
		ft_printf("pb\n");
	}
}

void	ft_insert(t_list *a, int num)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	ft_printf("num: %d\n", num);
	print_list(a);
	if (a == NULL || new == NULL || !num)
	{
		ft_printf("exit\n");
		print_list(a);
		print_list(new);
		exit(0);
	}
	ft_printf("num: %d\n", num);
	new->data = num;
	ft_printf("num: %d\n", num);
	new->next = a;
	new->prev = NULL;
	a = new;
	ft_printf("insert\n");
	print_list(a);
}

void	ft_delete(t_list *a)
{
	t_list	*to_delete;

	to_delete = a;
	a = a->next;
	free(to_delete);
}
