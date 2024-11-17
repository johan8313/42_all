/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:06:42 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/11 12:12:15 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr_gnl(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strdup_gnl(char *src)
{
	size_t	i;
	char	*copy;

	copy = (char *)malloc(sizeof(*copy) * (ft_strlen_gnl(src) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		++i;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*join;
	size_t		i;
	size_t		j;

	if (s1 == NULL)
		return (ft_strdup_gnl(s2));
	join = (char *)malloc(sizeof(*join)
			* (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		++i;
	}
	free(s1);
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}
