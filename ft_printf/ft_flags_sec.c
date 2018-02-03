/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_sec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:17:31 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/01 12:05:35 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		ft_flags_dot_int_help(char *s, t_struct *para, char *new_s,
size_t len)
{
	s[0] == '-' && para->p_ == 1 && para->s_ == 1 ?
	new_s = ft_strnew(para->d_++) : 0;
	para->p_ == 1 && para->nbr != -1 && para->d_ < (int)len ?
	new_s[0] = '+' : 0;
	para->p_ == 1 && para->nbr != -1 && para->d_ < (int)len ? para->p_-- : 0;
	para->s_ == 1 && para->p_ == 0 && para->d_ == 0 ? new_s[0] = ' ' : 0;
	s[0] == '-' && para->nbr > 0 ? new_s[0] = '-' : 0;
	s[0] == '-' && para->nbr < 1 ? ft_putchar('-') : 0;
	s[0] == '-' && para->nbr < 1 ? para->res++ : 0;
}

static int		ft_flags_dot_intbis(char *s, int n, char *new_s, t_struct *para)
{
	int x;

	x = 0;
	while (n < para->d_)
	{
		s[0] != '-' ? new_s[n++] = s[x++] : 0;
		s[0] == '-' ? (new_s[n++] = s[x + 1]) : 0;
		s[0] == '-' ? ++x : 0;
	}
	return (n);
}

char			*ft_flags_dot_int(char *s, size_t len, t_struct *para)
{
	char	*new_s;
	int		n;

	new_s = NULL;
	n = 0;
	s[0] == '-' ? len-- : 0;
	para->d_ == 0 && (para->chara == 'x' || para->chara == 'X' ||
	para->chara == 'o' || para->chara == 'O') ? s[0] = '\0' : 0;
	if (para->d_ < (int)len)
		return (s);
	s[0] != '-' || para->p_ != 1 || para->s_ != 1 ?
	new_s = ft_strnew(para->d_) : 0;
	ft_flags_dot_int_help(s, para, new_s, len);
	s[0] == '-' ? n -= 20 : 0;
	while (n < para->d_ - (int)len)
	{
		new_s[n] == 0 ? (new_s[n++] = '0') : n++;
	}
	n = ft_flags_dot_intbis(s, n, new_s, para);
	new_s[n] = '\0';
	para->s_ = 0;
	if (s)
		free(s);
	return (new_s);
}

char			*ft_flags_less(char *s, size_t len, t_struct *para)
{
	int		n;
	char	*new_s;
	int		len_less;

	if (para->nbr < (int)len)
		return (s);
	len_less = para->nbr;
	para->s_ == 1 || para->p_ == 1 ? len_less-- : 0;
	new_s = ft_strnew(para->nbr);
	n = 0;
	while (n < (int)len)
	{
		new_s[n] = s[n];
		n++;
	}
	while (n < len_less)
	{
		new_s[n++] = ' ';
	}
	para->p_ == 1 ? ft_putchar('+') : 0;
	para->p_ == 1 ? para->res++ : 0;
	para->p_ == 1 ? para->p_-- : 0;
	if (s)
		free(s);
	return (new_s);
}
