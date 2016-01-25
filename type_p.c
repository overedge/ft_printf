/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:38:02 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/25 11:38:44 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putstr_left(t_var *e, unsigned long value, char up)
{
	if (e->f_positive == 1)
		ft_putchar_ret('+', e);
	else if (e->f_positive == 0 && e->f_space == 1)
		ft_putchar_ret(' ', e);
	if (e->f_precis != 1 && e->f_width < e->f_precis && e->t_size < e->f_precis)
		ft_put_space(e->f_precis - e->t_size, e);
	else if (e->f_precis != 1 && e->f_width > e->f_precis)
		ft_put_space(1, e);
	ft_putstr("0x");
	e->ret += 2;
	ft_itoa_base(value, 16, up);
	if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size && \
			e->f_precis == 1)
		ft_put_space(e->f_width - e->t_size, e);
	else if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size &&\
			e->f_precis != 1)
		ft_put_space(e->f_width - e->f_precis, e);
}

static void		ft_putstr_right(t_var *e, unsigned long value, char up)
{
	if (e->f_zero == 0 && e->f_precis == 1)
		ft_put_space(e->f_width - e->t_size, e);
	else if (e->f_precis != 1 && e->f_width > e->f_precis)
		ft_put_space(e->f_width - e->t_size - 1, e);
	if (e->f_positive == 1)
		ft_putchar_ret('+', e);
	if (e->f_zero == 1 && e->f_precis == 1)
		ft_put_zero(e->f_width - e->t_size, e);
	else if (e->f_precis != 1 && e->f_width < e->f_precis)
		ft_put_space(e->f_precis - e->f_width + 2, e);
	else if (e->f_precis != 1 && e->f_width > e->f_precis)
		ft_put_space(1, e);
	if (e->f_positive == 0 && e->f_space == 1 && e->f_precis == 0)
		ft_putchar_ret(' ', e);
	ft_putstr("0x");
	e->ret += 2;
	ft_itoa_base(value, 16, up);
}

void			type_p(t_var *e)
{
	unsigned long	value;

	value = va_arg(e->ap, unsigned long);
	e->t_size = ft_itoa_count(value, 16, e);
	if (e->f_effect == 1)
		e->t_size += 2;
	if (e->f_left == 0 && e->f_width != 0 && e->f_width > e->t_size)
		ft_putstr_right(e, value, 1);
	else
		ft_putstr_left(e, value, 1);
}
