/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 08:14:09 by anonymou          #+#    #+#             */
/*   Updated: 2018/01/24 13:35:11 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_putaddrr_help(int i, long long int p, char *str)
{
	p > 0 ? str[i--] = 0 : 0;
	p == 0 ? str[i] = 0 : 0;
	p == 0 ? (str[--i] = '0') && (i--) : 0;
	return (i);
}

static char		*ft_putaddrr(long long int p)
{
	char const		*base;
	long long		tmp;
	int				i;
	char			*str;

	base = "0123456789abcdef";
	p < 0 ? p -= 4294967296 : 0;
	tmp = p;
	i = 3;
	while (p >= 16)
	{
		1 ? (p /= 16) && (i++) : 0;
	}
	str = ft_strnew(i);
	p = tmp;
	i = ft_putaddrr_help(i, p, str);
	while (p > 0)
	{
		tmp = p & BINAIRE_HEX;
		str[i--] = base[(tmp % 16)];
		p >>= 4;
	}
	str[i--] = 'x';
	str[i] = '0';
	return (str);
}

void			ft_p(t_struct *para, char *p)
{
	int len;
	int len_less;

	len = ft_strlen(p);
	if (para->nbr != '\0')
		p = ft_flags_height(p, len, para);
	len_less = ft_strlen(p);
	para->res = ft_strlen(p) + para->res;
	ft_putstr(p);
	if (p)
		free(p);
}

void			ft_p_main(t_struct *para, va_list args)
{
	char	*p;

	if (para->f_one == '\0')
	{
		p = ft_putaddrr(va_arg(args, long long int));
		ft_p(para, p);
	}
}
