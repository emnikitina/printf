/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:05:31 by odomenic          #+#    #+#             */
/*   Updated: 2020/11/20 20:38:11 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_include(char c, const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	size;

	i = 0;
	size = 0;
	if (s1 == NULL)
		return ((char *)s1);
	len = ft_strlen(s1) - 1;
	while ((s1[i] != '\0') && (ft_include(s1[i], set)))
		i++;
	if (i < len)
	{
		while ((len > 0) && (ft_include(s1[len], set)))
			len--;
	}
	size = len - i + 1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(str, (s1 + i), size);
	str[size] = '\0';
	return (str);
}
