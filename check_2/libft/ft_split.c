/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:11:24 by johmarti          #+#    #+#             */
/*   Updated: 2023/11/09 20:11:24 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcpy_c(char *dest, char const *src, char c)
{
	int	decalage;

	decalage = 0;
	while (*src && *src != c)
	{
		*dest = *src;
		++dest;
		++src;
		++decalage;
	}
	*dest = '\0';
	return (decalage);
}

static int	ft_strlen_c(char const *str, char c)
{
	int	len;

	len = 0;
	while (*str && *str != c)
	{
		++str;
		++len;
	}
	return (len);
}

static int	ft_nbstr_c(char const *str, char c)
{
	int	len;

	len = 0;
	while (*str)
	{
		while (*str && *str == c)
			++str;
		if (*str)
			++len;
		while (*str && *str != c)
			++str;
	}
	return (len);
}

char	**ft_split(char const *str, char c)
{
	char	**s1;
	int		i;

	if (!str)
		return (NULL);
	s1 = (char **)malloc(sizeof(*s1) * (ft_nbstr_c(str, c) + 1));
	if (!s1)
		return (NULL);
	i = 0;
	while (*str && *str == c)
		++str;
	while (*str)
	{
		s1[i] = (char *)malloc(sizeof(**s1) * (ft_strlen_c(str, c) + 1));
		if (!s1[i])
			return (NULL);
		str = str + ft_strcpy_c(s1[i], str, c);
		++i;
		while (*str && *str == c)
			++str;
	}
	s1[i] = 0;
	return (s1);
}
