/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:25:59 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/25 13:46:30 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack(char **argv, t_list **a)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		fill_stack_a(a, ft_atoi(argv[i]), i);
		i++;
	}
}

void	fill_stack_a(t_list **a, int num, int index)
{
	t_list	*new_element;
	t_list	*temp;

	new_element = malloc(sizeof(*new_element));
	temp = *a;
	new_element->data = num;
	new_element->index = index;
	new_element->next = NULL;
	if (!(*a))
	{
		new_element->prev = NULL;
		*a = new_element;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		new_element->prev = temp;
		temp->next = new_element;
	}
}

t_list	*initialisation ()
{
	t_list		*list;
	//t_element 	*element;

	list = malloc(sizeof(*list));
	//element = malloc(sizeof(*element));

	if (list == NULL)// || element == NULL)
		exit(0);
	//element->data = 0;
	//element->next = NULL;
	//list->first = element;
	//list = NULL;
	return (list);
}


int	main(int argc, char **argv)
{
	t_list	*a = initialisation();
	t_list	*b = initialisation();

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (check_errors(ft_split(argv[1], ' ')) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	else
		if (check_errors(argv) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		else
		{
			get_stack(argv, &a);
			//print_list_ab(a, b);
			//reverse_rotate(&a);
			//sa(&a);
			print_list_ab(a, b);
			push(a, b, 'b');
			//push(a, b, 'b');
			print_list_ab(a, b);
		}
}
