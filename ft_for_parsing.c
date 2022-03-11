/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:02:40 by odomenic          #+#    #+#             */
/*   Updated: 2020/12/27 13:50:11 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(const char *str, t_info *str_info)
{
	int i;

	i = 0;
	while ((str[i] == '-') || (str[i] == '0'))
	{
		if ((str[i] == 0) && ((str[i + 1] == '.') || (ft_isalpha(str[i + 1]))))
		{
			str_info->width = str[i];
			break ;
		}
		else
		{
			if ((str_info->flags != '-') || (str[i] != '0'))
				str_info->flags = str[i];
		}
		i++;
	}
	return (i);
}

int		ft_get_w(t_info *str_info, va_list args)
{
	str_info->width = va_arg(args, int);
	if (str_info->width < 0)
	{
		str_info->flags = '-';
		str_info->width *= -1;
	}
	return (1);
}

int		ft_get_width(const char *str, t_info *str_info)
{
	int		i;
	int		k;
	char	*str_for_width;

	i = 0;
	if (str[i] == '-')
	{
		str_info->flags = str[i];
		i++;
	}
	k = 0;
	while (ft_isdigit(str[i + k]))
		k++;
	if (!(str_for_width = (char *)malloc(sizeof(char) * (k + 1))))
		return (-1);
	ft_strlcpy(str_for_width, &str[i], k + 1);
	str_info->width = ft_atoi(str_for_width);
	free(str_for_width);
	i += k;
	return (i);
}

int		ft_get_prec(const char *str, t_info *str_info, va_list args)
{
	int		i;
	char	*str_for;
	int		k;

	i = 0;
	k = 0;
	str_info->precision = 0;
	if (str[i] == '*')
	{
		str_info->precision = va_arg(args, int);
		if (str_info->precision < 0)
			str_info->precision = -1;
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i + k]))
			k++;
		if (!(str_for = (char *)malloc(sizeof(char) * (k + 1))))
			return (-1);
		ft_strlcpy(str_for, &str[i], k + 1);
		str_info->precision = ft_atoi(str_for);
		free(str_for);
	}
	return (i + k);
}

int		ft_get_width_prec(const char *str, t_info *str_info, va_list args)
{
	int i;
	int k;

	i = 0;
	if (str[i] == '*')
		i += ft_get_w(str_info, args);
	else if ((ft_isdigit(str[i])) || (str[i] == '-'))
	{
		if ((k = ft_get_width(&str[i], str_info)) == -1)
			return (-1);
		else
			i += k;
	}
	if (str[i] == '.')
	{
		i++;
		if ((k = ft_get_prec(&str[i], str_info, args)) == -1)
			return (-1);
		else
			i += k;
	}
	return (i);
}
