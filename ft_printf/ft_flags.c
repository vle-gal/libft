/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:34:29 by vle-gal           #+#    #+#             */
/*   Updated: 2018/01/24 16:43:24 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_flags_help(t_struct *para, char *new_s, int n)
{
	para->s_ == 1 && para->p_ == 0 ? new_s[0] = ' ' : 0;
	para->p_ == 1 && para->z_ == 1 && para->d_ == -1 ? new_s[0] = '+' : 0;
	para->p_ == 1 && para->z_ == 1 && para->d_ > 0 ?
	new_s[n - 1] = '+' : 0;
	para->p_ == 1 && para->z_ == 0 ? new_s[n - 1] = '+' : 0;
}

char		*ft_flags_height(char *s, size_t len, t_struct *para)
{
	int		a;
	int		n;
	char	*new_s;

	n = 0;
	a = para->nbr - (int)len;
	if (a > 0)
	{
		new_s = ft_strnew(para->nbr);
		while (a > 0)
		{
			para->z_ == 1 && para->d_ == -1 ? new_s[n] = '0' : 0;
			para->z_ != 1 || para->d_ != -1 ? new_s[n] = ' ' : 0;
			1 ? a-- && (n++) : 0;
		}
		ft_flags_help(para, new_s, n);
		while (s[a])
			s[a] != 0 ? (new_s[n] = s[a]) && (n++) && (a++) : 0;
		if (s)
			free(s);
		return (new_s);
	}
	return (s);
}

static int	ft_flags_height_int_help(char *new_s, t_struct *para, int a)
{
	while (a > 0)
	{
		para->z_ == 1 && para->d_ == -1 ? new_s[para->n] = '0' : 0;
		para->z_ != 1 || para->d_ != -1 ? new_s[para->n] = ' ' : 0;
		para->n++;
		a--;
	}
	para->p_ == 1 && para->nbr != -1 && para->d_ > 0 ?
	new_s[para->n - 1] = '+' : 0;
	para->p_ == 1 && para->nbr != -1 && para->d_ > 1 ? para->p_-- : 0;
	para->p_ == 1 && para->d != -1 && para->z_ != 1 ? ft_putchar('+') : 0;
	para->p_ == 1 && para->d != -1 && para->z_ != 1 ? para->p_-- : 0;
	para->s_ == 1 && para->p_ == 0 ? new_s[0] = ' ' : 0;
	para->p_ == 1 && para->z_ == 1 && para->d_ == -1 ? new_s[0] = '+' : 0;
	para->p_ == 1 && para->z_ == 1 && para->d_ > 0 ?
	new_s[para->n - 1] = '+' : 0;
	para->p_ == 1 && para->z_ == 0 ? new_s[para->n - 1] = '+' : 0;
	return (a);
}

char		*ft_flags_height_int(char *s, size_t len, t_struct *para)
{
	int		a;
	char	*new_s;

	para->n = 0;
	para->s_ == 1 && para->p_ == 0 ? para->nbr-- : 0;
	a = para->nbr - (int)len;
	if (a > 0)
	{
		new_s = ft_strnew(para->nbr + 2);
		a = ft_flags_height_int_help(new_s, para, a);
		while (s[a])
		{
			new_s[para->n] = s[a];
			s[a] == '-' && para->z_ == 1 ? new_s[0] = '-' : 0;
			s[a] == '-' && para->z_ == 1 ? new_s[para->n] = '0' : 0;
			para->n++;
			a++;
		}
		if (s)
			free(s);
		return (new_s);
	}
	return (s);
}

char		*ft_flags_dot(char *s, size_t len, t_struct *para)
{
	int		n;
	int		x;
	char	*new_s;

	n = 0;
	x = 0;
	if (para->d_ < (int)len)
		return (s);
	else
	{
		new_s = ft_strnew((size_t)para->d_);
		while (n < (para->d_ - (int)len))
			new_s[n++] = '0';
		while (n < para->d_)
		{
			new_s[n] = s[x];
			x++;
			n++;
		}
		if (s)
			free(s);
		return (new_s);
	}
	return (s);
}
