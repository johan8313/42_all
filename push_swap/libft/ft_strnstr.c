/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:51:26 by johmarti          #+#    #+#             */
/*   Updated: 2023/11/08 11:51:26 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_little;
	size_t	l_big;

	if (!*little)
		return ((char *)big);
	l_little = ft_strlen(little);
	l_big = ft_strlen(big);
	while (*big && len >= l_little && l_little <= l_big)
	{
		if (!ft_strncmp(big, little, l_little))
			return ((char *)big);
		--len;
		--l_big;
		++big;
	}
	return (NULL);
}
