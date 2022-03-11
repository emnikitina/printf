/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:03:01 by odomenic          #+#    #+#             */
/*   Updated: 2020/12/27 12:56:33 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len_hex(long int n)
{
	long int	n_copy;
	size_t		len;

	len = 0;
	n_copy = n;
	if (n_copy < 0)
		n_copy *= -1;
	if (n_copy == 0)
		len++;
	else
	{
		while (n_copy != 0)
		{
			len++;
			n_copy /= 16;
		}
	}
	return (len);
}

void	ft_neg_tran(char *str, int *k, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]))
			k[i] = 15 - (str[i] - '0');
		else
			k[i] = 15 - (str[i] - 'a' + 10);
		i++;
	}
	i = 0;
	k[len - 1] += 1;
	i = len - 1;
	while (k[i] > 15)
	{
		k[i] %= 16;
		k[i - 1]++;
		i--;
	}
}

void	ft_negative(char *str, int len, int i)
{
	int	k[len - 1];

	while (i > -1)
	{
		str[i] = '0';
		i--;
	}
	i++;
	ft_neg_tran(str, k, len);
	i = 0;
	while (i < len)
	{
		if (k[i] > 9)
			str[i] = 'a' + (k[i] % 10);
		else
			str[i] = '0' + k[i];
		i++;
	}
}

void	ft_nbrs_hex(char *str, unsigned long int n, int len, int f)
{
	int		i;

	i = len;
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0' + n;
	while (n != 0)
	{
		if ((n % 16) > 9)
			str[i] = 'a' + ((n % 16) % 10);
		else
			str[i] = '0' + (n % 16);
		n /= 16;
		i--;
	}
	if (f == -1)
		ft_negative(str, len, i);
}

char	*ft_to_hexa(long int n)
{
	char	*str;
	size_t	len;
	int		f;

	if (n < 0)
		len = (1 + (ft_len_hex(n) - 1) / 8) * 8;
	else
		len = ft_len_hex(n);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	f = 1;
	if (n < 0)
	{
		f = -1;
		n *= -1;
	}
	ft_nbrs_hex(str, n, (int)len, f);
	return (str);
}
