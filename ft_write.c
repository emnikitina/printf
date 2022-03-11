/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:22:48 by odomenic          #+#    #+#             */
/*   Updated: 2021/01/07 18:17:05 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_s(va_list args)
{
	char *str;
	char *s;

	s = va_arg(args, char *);
	if (s == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(s);
	return (str);
}

char	*ft_to_str(char t, va_list args)
{
	char *str;
	char *s;

	if (t == '%')
		str = ft_strdup("%");
	else if (t == 's')
		str = ft_get_s(args);
	else if ((t == 'd') || (t == 'i'))
		str = ft_itoa(va_arg(args, int));
	else if (t == 'p')
	{
		s = ft_to_hexa(va_arg(args, uintptr_t));
		str = ft_strjoin("0x", s);
		free(s);
	}
	else if (t == 'u')
		str = ft_un_int(va_arg(args, unsigned int));
	else if (t == 'x')
		str = ft_to_hexa(va_arg(args, int));
	else if (t == 'X')
		str = ft_upper_str(ft_to_hexa(va_arg(args, int)));
	else
		return (NULL);
	return (str);
}

char	*ft_width_prec(t_info *str, char *s)
{
	char *s1;

	if (str->precision != -1)
	{
		s1 = s;
		if (!(s = ft_precision(str->type, s, str->precision)))
			return (NULL);
		free(s1);
	}
	if ((str->flags == '0') && (str->precision > -1) && ((str->type == 'd')
				|| (str->type == 'i') || (str->type == 'u') ||
				(str->type == 'x') || (str->type == 'X')))
		str->flags = '*';
	if (str->width != -1)
	{
		s1 = s;
		if (!(s = ft_width(str->width, s, str->flags)))
			return (NULL);
		free(s1);
	}
	return (s);
}

int		ft_to_write(t_info str, va_list args)
{
	size_t	len;
	char	*s;

	if (str.type == 'c')
		len = ft_char(str.flags, str.width, args);
	else
	{
		if (str.type == 'p')
		{
			if (!(s = ft_pointer(str, args)))
				return (-1);
		}
		else
		{
			if (!(s = ft_to_str(str.type, args)))
				return (-1);
			if (!(s = ft_width_prec(&str, s)))
				return (-1);
		}
		len = ft_strlen(s);
		write(1, s, len);
		free(s);
	}
	return (len);
}
