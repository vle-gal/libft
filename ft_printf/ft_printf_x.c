/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 15:07:42 by anonymou          #+#    #+#             */
/*   Updated: 2018/01/24 13:34:23 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_xstr_help(long long int p, int i, char *str)
{
	p == 0 ? str[i] = 0 : 0;
	p == 0 ? str[--i] = '0' : 0;
	p > 0 ? str[i--] = 0 : 0;
	p == 0 ? --i : 0;
	return (i);
}

static char		*ft_xstr(long long int p)
{
	char const	*base;
	long long	tmp;
	int			i;
	char		*str;

	base = "0123456789abcdef";
	p < 0 ? p += 4294967296 : 0;
	tmp = p;
	i = 1;
	while (p >= 16)
	{
		1 ? (p /= 16) && (i++) : 0;
	}
	str = ft_strnew(i);
	p = tmp;
	i = ft_xstr_help(p, i, str);
	while (p > 0)
	{
		tmp = p & BINAIRE_HEX;
		str[i--] = base[(tmp % 16)];
		p >>= 4;
	}
	return (str);
}

static char		*ft_xstrll(long long p, t_struct *para)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)p;
	para->x = adr;
	i = 0;
	base = "0123456789abcdef";
	while ((para->x / 16) > 0)
	{
		para->x /= 16;
		i++;
	}
	res = ft_strnew(i + 1);
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	return (res);
}

static char		*ft_xstrh(short p, t_struct *para)
{
	unsigned long	adr;
	char const		*base;
	char			*res;
	int				i;

	adr = (unsigned long)p;
	para->x = adr;
	i = 0;
	base = "0123456789abcdef";
	while ((para->x / 16) > 0)
	{
		para->x /= 16;
		i++;
	}
	res = ft_strnew(i);
	while ((adr / 16) > 0)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[0] = base[(adr % 16)];
	return (res);
}

void			ft_x_main(t_struct *para, va_list args)
{
	char	*x;

	para->f_one == '\0' ? x = ft_xstr(va_arg(args, int)) : 0;
	if (para->f_one == 'l')
	{
		para->f_two == '\0' ? x = ft_xstr(va_arg(args, long)) : 0;
		para->f_two == 'l' ? x = ft_xstr(va_arg(args, long long)) : 0;
	}
	if (para->f_one == 'h')
	{
		para->f_two == '\0' ? x = ft_xstrh((short)va_arg(args, int), para) : 0;
		para->f_two == 'h' ? x = ft_xstrhh((char)va_arg(args, int), para) : 0;
	}
	para->f_one == 'j' ? x = ft_xstrll(va_arg(args, long long), para) : 0;
	para->f_one == 'z' ? x = ft_xstr(va_arg(args, long)) : 0;
	para->chara == 'X' ? x = ft_xmaj(x) : 0;
	para->h_ == 1 ? ft_xhtag(para, x) : ft_x_draw(para, x);
	para->xdoth = 0;
}
