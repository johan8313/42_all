/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_removed_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:52:49 by johmarti          #+#    #+#             */
/*   Updated: 2024/02/27 19:10:27 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int	comp(void *a, void *b)
{
	if (a = b)
		return (0);
	return (1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*comp)())
{
	t_list *list= malloc(sizeof(*list));
	int	i;

	i = 0;
	while (begin_list[i] != NULL)
	{
		comp(begin_list->data)
	}
}
