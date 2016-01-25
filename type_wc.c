/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_wc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:48:23 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/25 11:50:45 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putwchar(unsigned long str)
{
	write(1, &str, sizeof(wchar_t));
}

static void		ft_putstr_left(unsigned long str, t_var *e)
{
	ft_putwchar(str);
	e->ret++;
	ft_put_space(e->f_width - 1, e);
}

static void		ft_putstr_right(unsigned long str, t_var *e)
{
	if (e->f_zero == 0)
		ft_put_space(e->f_width - 1, e);
	else
		ft_put_zero(e->f_width - 1, e);
	ft_putwchar(str);
	e->ret++;
}

void			type_wc(t_var *e)
{
	unsigned long str;

	str = va_arg(e->ap, unsigned long);
	if (e->f_width == 0)
	{
		ft_putwchar(str);
		e->ret++;
		return ;
	}
	else if (e->f_width != 0 && e->f_left == 1)
		ft_putstr_left(str, e);
	else if (e->f_width != 0 && e->f_left == 0)
		ft_putstr_right(str, e);
}
