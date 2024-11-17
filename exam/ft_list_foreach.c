/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:11:36 by johmarti          #+#    #+#             */
/*   Updated: 2024/02/27 18:49:05 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list_foreach.h"
#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void	ft_list_foreach(t_list *begin_list, void *(f)(void *))
{
	t_list	*list_ptr;
	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

#include <stdio.h>
#include <stddef.h>

void	*square_number(void *a)
{
	int	*mem;

	mem = (int *)a;
	*mem *= *mem;
	a = mem;
	return (a);
}

int	main()
{
	t_list	*begin_list = malloc(sizeof(*begin_list));
	t_list	*next = malloc(sizeof(*next));
	//struct s_list begin_list = { .data = (void *)12};
	//struct s_list next;

	int	data_1 = 5;
	int *p_data_1 = &data_1;
	int	data_2 = 20;
	int	*p_data_2 = &data_2;
	//void (*square_number_ptr)(void);
	//void *ptr;
	//square_number_ptr = &square_number;
	//ptr = &square_number_ptr;

	next->data = p_data_2;
	next->next = NULL;
	begin_list->data = p_data_1;
	begin_list->next = next;

	printf("main_avant\n");
	printf("%d\n", data_1);
	printf("%d\n", data_2);
	ft_list_foreach(begin_list, *(square_number));
	printf("main_apres\n");
	printf("%d\n", data_1);
	printf("%d\n", data_2);
}
