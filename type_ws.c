/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 22:20:22 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/30 21:27:54 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strwlen(wchar_t *str)
{
	int		i;
	
	i = 0;
	while (*str++)
		i++;
	return (i);
}

static void	ft_putwchar(wchar_t chr, t_var *e)
{
	if (chr <= 0x7F)
		ft_putchar_ret(chr, e);
	else if (chr <= 0x7FF)
	{
		ft_putchar_ret((chr >> 6) + 0xC0, e);
		ft_putchar_ret((chr & 0x3F) + 0x80, e);
	}
	else if (chr <= 0xFFFF)
	{
		ft_putchar_ret((chr >> 12) + 0xE0, e);
		ft_putchar_ret(((chr >> 6) & 0x3F) + 0x80, e);
		ft_putchar_ret((chr & 0x3F) + 0x80, e);
	}
	else if (chr <= 0x1FFFFF)
	{
		ft_putchar_ret((chr >> 18) + 0xF0, e);
		ft_putchar_ret(((chr >> 12) & 0x3F) + 0x80, e);
		ft_putchar_ret(((chr >> 6) & 0x3F) + 0x80, e);
		ft_putchar_ret((chr & 0x3F) + 0x80, e);
	}
}

static void	ft_putwstr(wchar_t *str, t_var *e)
{
	while(*str)
		ft_putwchar(*str++, e);
}

static void		ft_putstr_left(wchar_t *str, t_var *e)
{
	ft_putwstr(str, e);
	ft_put_space(e->f_width - ft_strwlen(str), e);
}

static void		ft_putstr_right(wchar_t *str, t_var *e)
{
	ft_put_space(e->f_width - ft_strwlen(str), e);
	ft_putwstr(str, e);
}

void			type_ws(t_var *e)
{
	wchar_t *str;
	wchar_t *res;

	res = va_arg(e->ap, wchar_t*);
	if (!res)
	{
		ft_putstr("(null)");
		e->ret += 6;
		return ;
	}
	if (e->f_zero == 1)
		return ;
	str = res;
	//if (e->f_precis != 1)
	//	str = ft_strsub(str, 0, e->f_precis);
	if (e->f_width == 0)
	{
		ft_putwstr(str, e);
		return ;
	}
	else if (e->f_width != 0 && e->f_left == 1)
		ft_putstr_left(str, e);
	else if (e->f_width != 0 && e->f_left == 0)
		ft_putstr_right(str, e);
}