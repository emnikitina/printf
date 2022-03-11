/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odomenic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:30:33 by odomenic          #+#    #+#             */
/*   Updated: 2020/12/27 14:14:32 by odomenic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct	s_info
{
	char		flags;
	int			width;
	int			precision;
	char		type;
}				t_info;

int				ft_printf(const char *str, ...);
char			*ft_un_int(unsigned int n);
char			*ft_upper_str(char *str);
char			*ft_to_hexa(long int n);
char			*ft_width(int str_width, char *str_arg, char f);
char			*ft_precision(char t, char *str_arg, int prec);
int				ft_parsing_str(const char *str, va_list args,
		t_info *str_info);
int				ft_get_flag(const char *str, t_info *str_info);
int				ft_get_width(const char *str, t_info *str_info);
int				ft_get_prec(const char *str, t_info *str_info,
		va_list args);
int				ft_get_width_prec(const char *str, t_info *str_info,
		va_list args);
int				ft_to_write(t_info str, va_list args);
int				ft_char(char flag, int width, va_list args);
char			*ft_pointer(t_info str, va_list args);

#endif
