/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:08:39 by odomenic          #+#    #+#             */
/*   Updated: 2021/01/07 17:34:15 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_dec(unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		len++;
	else
	{
		while (n != 0)
		{
			len++;
			n /= 10;
		}
	}
	return (len);
}

char	*ft_un_int(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_len_dec(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	len--;
	while (len > -1)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_upper_str(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
