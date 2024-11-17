/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:16:13 by johmarti          #+#    #+#             */
/*   Updated: 2024/02/09 14:52:04 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unsigned_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_length;
	char	*str;

	print_length = 0;
	if (n == 0)
		print_length += write(1, "0", 1);
	else
	{
		str = ft_uitoa(n);
		print_length = ft_printstr(str);
		free(str);
	}
	return (print_length);
}
