/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:31:55 by odomenic          #+#    #+#             */
/*   Updated: 2021/01/13 21:48:17 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsing_str(const char *str, va_list args, t_info *str_info)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i += ft_get_flag(&str[0], str_info);
		i += ft_get_width_prec(&str[i], str_info, args);
		if ((str[i] == 'c') || (str[i] == 's') || (str[i] == 'i') ||
				(str[i] == 'd') || (str[i] == 'p') || (str[i] == 'x') ||
				(str[i] == 'X') || (str[i] == '%') || (str[i] == 'u'))
		{
			str_info->type = str[i];
			return (i + 1);
		}
		i++;
	}
	return (-1);
}

int		ft_process(const char *str, va_list args)
{
	int		k;
	int		len;
	t_info	struct_str;

	len = 0;
	while (*str != '\0')
	{
		if (*str != '%')
		{
			len += write(1, str, 1);
			str++;
		}
		else
		{
			struct_str = (t_info){'*', -1, -1, '*'};
			if ((k = ft_parsing_str((str + 1), args, &struct_str)) == -1)
				return (-1);
			str += (k + 1);
			if ((len += ft_to_write(struct_str, args)) == -1)
				return (-1);
		}
	}
	return (len);
}

int		ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = ft_process(str, args);
	va_end(args);
	//write(1, "c", 1);
	return (len + 1);
}
