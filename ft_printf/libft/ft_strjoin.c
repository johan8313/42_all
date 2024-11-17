/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:10:54 by johmarti          #+#    #+#             */
/*   Updated: 2023/11/09 20:10:54 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sptr;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	sptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sptr)
		return (NULL);
	index = 0;
	while (*s1)
	{
		sptr[index] = *s1;
		++s1;
		++index;
	}
	while (*s2)
	{
		sptr[index] = *s2;
		++s2;
		++index;
	}
	sptr[index] = '\0';
	return (sptr);
}
