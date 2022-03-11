/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:05:54 by odomenic          #+#    #+#             */
/*   Updated: 2020/11/14 20:07:49 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	str = (char *)s;
	len = ft_strlen(str) + 1;
	while (i < len)
	{
		if (str[i] == (unsigned char)c)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
