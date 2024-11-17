/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:08:35 by johmarti          #+#    #+#             */
/*   Updated: 2023/11/09 20:08:35 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_ret;
	size_t	len;

	len = ft_strlen(s);
	s_ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!s_ret)
		return (NULL);
	s_ret = ft_memcpy(s_ret, s, len + 1);
	return (s_ret);
}
