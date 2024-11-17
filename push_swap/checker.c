/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:25:40 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/23 10:44:53 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_errors(char **argv)
{
	if (ft_argv_is_integer(argv) == 0)
		return (0);
	if (ft_argv_max_min(argv) == 0)
		return (0);
	if (ft_duplicates(argv) == 0)
		return (0);
	return (1);
}

int	ft_argv_max_min(char **argv)
{
	argv++;
	while (*argv)
	{
		if (ft_atoi(*argv) > 2147483647 || ft_atoi(*argv) < -2147483648)
			return (0);
		(argv)++;
	}
	return (1);
}

int	ft_argv_is_integer(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	while (argv[i])
	{
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		//if (argv[i][j] == '0')
		//	return (0);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
