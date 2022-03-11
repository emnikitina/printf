/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 22:06:59 by odomenic          #+#    #+#             */
/*   Updated: 2020/11/22 16:30:15 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (!(len_needle))
		return ((char *)haystack);
	if (len_needle <= ft_strlen(haystack))
	{
		while ((*haystack != '\0') && (i < len))
		{
			if ((*haystack == *needle) && ((len - i) >= len_needle))
			{
				if (!(ft_strncmp(haystack, needle, len_needle)))
					return ((char *)haystack);
			}
			haystack++;
			i++;
		}
	}
	return (NULL);
}
