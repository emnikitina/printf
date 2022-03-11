/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:51:40 by odomenic          #+#    #+#             */
/*   Updated: 2020/12/27 14:10:24 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char(char flag, int width, va_list args)
{
	char	c;
	int		len;

	len = 0;
	c = (char)va_arg(args, int);
	if (flag == '-')
		len += write(1, &c, 1);
	if (width != -1)
	{
		while (width > 1)
		{
			len += write(1, " ", 1);
			width--;
		}
	}
	if (flag == '*')
		len += write(1, &c, 1);
	return (len);
}

char	*ft_pointer(t_info str, va_list args)
{
	char *s;
	char *s1;

	s = ft_to_hexa(va_arg(args, uintptr_t));
	if (str.precision != -1)
	{
		s1 = s;
		s = ft_precision('p', s, str.precision);
		free(s1);
	}
	s1 = s;
	s = ft_strjoin("0x", s);
	free(s1);
	if (str.width != -1)
	{
		s1 = s;
		s = ft_width(str.width, s, str.flags);
		free(s1);
	}
	return (s);
}
