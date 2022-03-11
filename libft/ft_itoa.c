/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:34:38 by odomenic          #+#    #+#             */
/*   Updated: 2020/11/16 20:26:53 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	put_nbrs(char *str, int n, size_t len)
{
	str += (len - 1);
	*str = '\0';
	str--;
	if (n == -2147483648)
	{
		*str = '0' + (-(n % 10));
		n /= 10;
		str--;
	}
	if (n < 0)
		n *= -1;
	if (n == 0)
		*str = '0' + n;
	while (n != 0)
	{
		*str = '0' + (n % 10);
		n /= 10;
		str--;
	}
}

static	size_t	ft_len(int *n)
{
	int		n_copy;
	size_t	len;

	len = 1;
	n_copy = *n;
	if (n_copy == 0)
		len++;
	else
	{
		while (n_copy != 0)
		{
			len++;
			n_copy /= 10;
		}
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_len(&n);
	if (n >= 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		put_nbrs(str, n, len);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		*str = '-';
		str++;
		put_nbrs(str, n, len);
		str--;
	}
	return (str);
}
