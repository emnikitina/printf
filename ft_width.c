/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:25:56 by odomenic          #+#    #+#             */
/*   Updated: 2020/12/26 20:53:11 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero(char *str_arg, int len, char f, char *s)
{
	char	*str;

	if (!(str = ft_strdup("")))
		return (NULL);
	if (str_arg[0] == '-')
	{
		len++;
		if (!(s = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_memset(s, f, len);
		s[0] = '-';
		str = ft_strjoin(s, &str_arg[1]);
	}
	else
	{
		ft_memset(s, f, len);
		str = ft_strjoin(s, str_arg);
	}
	return (str);
}

char	*ft_width(int str_width, char *str_arg, char f)
{
	int		len;
	char	*s;
	char	*str;

	if ((len = str_width - ft_strlen(str_arg)) > 0)
	{
		if (!(s = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		s[len] = '\0';
		if (f == '0')
			str = ft_zero(str_arg, len, f, s);
		else
		{
			ft_memset(s, ' ', len);
			if (f == '-')
				str = ft_strjoin(str_arg, s);
			else
				str = ft_strjoin(s, str_arg);
		}
		free(s);
	}
	else if (!(str = ft_strdup(str_arg)))
		return (NULL);
	return (str);
}
