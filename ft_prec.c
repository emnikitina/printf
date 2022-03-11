/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:08:27 by odomenic          #+#    #+#             */
/*   Updated: 2020/12/27 13:00:00 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_nbr_neg(char *str_arg, int prec)
{
	int		len;
	char	*s;
	char	*str;

	if (!(str = ft_strdup("")))
		return (NULL);
	if ((len = prec - (ft_strlen(str_arg) - 1)) > 0)
	{
		free(str);
		if (!(s = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_memset(s, '0', len + 1);
		s[0] = '-';
		str = ft_strjoin(s, &str_arg[1]);
		free(s);
	}
	else if (!((ft_strlen(str_arg) == 1) && (str_arg[0] == '0') && (prec == 0)))
	{
		free(str);
		if (!(str = ft_strdup(str_arg)))
			return (NULL);
	}
	return (str);
}

char	*ft_nbr_pos(char *str_arg, int prec)
{
	int		len;
	char	*str;
	char	*s;

	if (!(str = ft_strdup("")))
		return (NULL);
	if ((len = prec - ft_strlen(str_arg)) > 0)
	{
		free(str);
		if (!(s = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_memset(s, '0', len);
		str = ft_strjoin(s, str_arg);
		free(s);
	}
	else if (!((ft_strlen(str_arg) == 1) && (str_arg[0] == '0') && (prec == 0)))
	{
		free(str);
		if (!(str = ft_strdup(str_arg)))
			return (NULL);
	}
	return (str);
}

char	*ft_for_nbr(char *str_arg, int prec)
{
	char	*str;

	if (!(str = ft_strdup("")))
		return (NULL);
	if (str_arg[0] == '-')
	{
		free(str);
		str = ft_nbr_neg(str_arg, prec);
	}
	else
	{
		free(str);
		str = ft_nbr_pos(str_arg, prec);
	}
	return (str);
}

char	*ft_precision(char t, char *str_arg, int prec)
{
	char	*str;

	if (!(str = ft_strdup("")))
		return (NULL);
	if (t == 's')
	{
		free(str);
		if (!(str = (char *)malloc(sizeof(char) * (prec + 1))))
			return (NULL);
		ft_strlcpy(str, str_arg, prec + 1);
	}
	else if ((t == 'd') || (t == 'i') || (t == 'u') || (t == 'x')
			|| (t == 'X') || (t == 'p'))
	{
		free(str);
		if (!(str = ft_for_nbr(str_arg, prec)))
			return (NULL);
	}
	return (str);
}
