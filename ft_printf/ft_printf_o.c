/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:40:46 by anonymou          #+#    #+#             */
/*   Updated: 2018/01/24 16:28:48 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_ostr(unsigned int p)
{
	unsigned int	tmp;
	int				i;
	char			*str;

	p -= 4294967296;
	tmp = p;
	i = 1;
	while (p >= 9)
	{
		p /= 8;
		i++;
	}
	str = ft_strnew(i);
	p = tmp;
	p > 0 ? str[i--] = 0 : 0;
	p == 0 ? str[i] = 0 : 0;
	p == 0 ? str[--i] = '0' : 0;
	while (p > 0)
	{
		tmp = p & BINAIRE_OCTAL;
		str[i--] = tmp + '0';
		p >>= 3;
	}
	return (str);
}

static char		*ft_ostrl(unsigned long p)
{
	unsigned long	tmp;
	int				i;
	char			*str;

	p -= 4294967296;
	tmp = p;
	i = 1;
	while (p >= 9)
	{
		p /= 8;
		i++;
	}
	str = ft_strnew(i);
	p = tmp;
	p > 0 ? str[i--] = 0 : 0;
	p == 0 ? str[i] = 0 : 0;
	p == 0 ? str[--i] = '0' : 0;
	while (p > 0)
	{
		tmp = p & BINAIRE_OCTAL;
		str[i--] = tmp + '0';
		p >>= 3;
	}
	return (str);
}

static char		*ft_ostrll(long long p)
{
	long long		tmp;
	int				i;
	char			*str;

	p -= 4294967296;
	tmp = p;
	i = 1;
	while (p >= 9)
	{
		p /= 8;
		i++;
	}
	str = ft_strnew(i);
	p = tmp;
	p > 0 ? str[i--] = 0 : 0;
	p == 0 ? str[i] = 0 : 0;
	p == 0 ? str[--i] = '0' : 0;
	while (p > 0)
	{
		tmp = p & BINAIRE_OCTAL;
		str[i--] = tmp + '0';
		p >>= 3;
	}
	return (str);
}

static char		*ft_ostrh(short p)
{
	int		tmp;
	int		i;
	char	*str;

	tmp = p;
	i = 1;
	while (p >= 9)
	{
		p /= 8;
		i++;
	}
	str = ft_strnew(i);
	p = tmp;
	p > 0 ? str[i--] = 0 : 0;
	p == 0 ? str[i] = 0 : 0;
	p == 0 ? str[--i] = '0' : 0;
	while (p > 0)
	{
		tmp = p & BINAIRE_OCTAL;
		str[i--] = tmp + '0';
		p >>= 3;
	}
	return (str);
}

void			ft_o_main(t_struct *para, va_list args)
{
	char	*o;

	para->f_one == '\0' ? o = ft_ostr(va_arg(args, int)) : 0;
	if (para->f_one == 'l')
	{
		para->f_two == '\0' ? o = ft_ostrl(va_arg(args, long)) : 0;
		para->f_two == 'l' ? o = ft_ostrll(va_arg(args, long long)) : 0;
	}
	if (para->f_one == 'h')
	{
		para->f_two == '\0' ? o = ft_ostrh((short)va_arg(args, int)) : 0;
		para->f_two == 'h' ? o = ft_ostrhh((char)va_arg(args, int)) : 0;
	}
	para->f_one == 'j' ? o = ft_ostrll(va_arg(args, long long)) : 0;
	para->f_one == 'z' ? o = ft_ostrl(va_arg(args, long)) : 0;
	para->d_ == 0 && o[0] == '0' ? o[0] = '0' : 0;
	para->h_ == 1 ? ft_ohtag(para, o) : ft_o_draw(para, o);
}
