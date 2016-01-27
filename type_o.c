/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:39:25 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/27 18:46:22 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					ft_putstr_left(t_var *e, unsigned long value)
{
	if (e->f_positive == 0 && e->f_space == 1)
		ft_putchar_ret(' ', e);
	if (e->f_precis != 1 && e->f_width < e->f_precis && e->t_size < e->f_precis)
		ft_put_zero(e->f_precis - e->t_size, e);
	else if (e->f_precis != 1 && e->f_width > e->f_precis)
		ft_put_zero(1, e);
	if (e->f_effect == 1 && value > 0)
	{
		ft_putstr("0");
		e->ret += 1;
	}
	ft_itoa_base(value, 8, 1);
	if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size && \
			e->f_precis == 1)
		ft_put_space(e->f_width - e->t_size, e);
	else if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size \
			&& e->f_precis != 1)
		ft_put_space(e->f_width - e->f_precis, e);
}

static void					ft_putstr_right(t_var *e, unsigned long value)
{
	if (e->f_zero == 0 && e->f_precis == 1)
		ft_put_space(e->f_width - e->t_size, e);
	else if (e->f_precis != 1 && e->f_width > e->f_precis)
		ft_put_space(e->f_width - e->t_size - 1, e);
	if (e->f_zero == 1 && e->f_precis == 1)
		ft_put_zero(e->f_width - e->t_size, e);
	else if (e->f_precis != 1 && e->f_width < e->f_precis)
		ft_put_space(e->f_precis - e->f_width + 2, e);
	else if (e->f_precis != 1 && e->f_width > e->f_precis)
		ft_put_space(1, e);
	if (e->f_positive == 0 && e->f_space == 1 && e->f_precis == 0)
		ft_putchar_ret(' ', e);
	if (e->f_effect == 1 && value > 0)
	{
		ft_putstr("0");
		e->ret += 1;
	}
	ft_itoa_base(value, 8, 1);
}

static unsigned long		ft_verif_exep_x(unsigned long value, t_var *e)
{
	if (e->f_hh && value > 255)
		value = 0;
	if (e->f_h && value > 65535)
		value = 0;
	return (value);
}


static void					exep_effect(t_var *e)
{
	ft_putchar('0');
	e->ret++;
	e->error = 1;
}

void						type_o(t_var *e)
{
	unsigned long	value;

	if (e->f_h == 0 && e->f_hh == 0 && e->f_ll == 0 && e->f_l == 0 && \
			e->f_j == 0 && e->f_z == 0 && e->U_exep == 0)
		value = va_arg(e->ap, unsigned int);
	else
		value = va_arg(e->ap, unsigned long);
	if (value == 0 && e->f_effect == 1)
		exep_effect(e);
	else if (e->f_precis == 0 && value == 0)
	{
		ft_put_space(e->f_width, e);
		return ;
	}
	value = ft_verif_exep_x(value, e);
	if (e->error == 1)
		return ;
	e->t_size = ft_itoa_count(value, 8, e);
	if (e->f_effect == 1)
		e->t_size += 1;
	if (e->f_left == 0 && e->f_width != 0 && e->f_width > e->t_size)
		ft_putstr_right(e, value);
	else
		ft_putstr_left(e, value);
}
