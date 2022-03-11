/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:06:14 by odomenic          #+#    #+#             */
/*   Updated: 2020/11/15 11:31:36 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	else
	{
		while (((len + i) < dstsize - 1) && (src[i] != '\0'))
		{
			dst[len + i] = src[i];
			i++;
		}
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
