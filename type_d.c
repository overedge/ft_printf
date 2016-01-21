/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:13:05 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/21 03:16:23 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putstr_left(t_var *e, int value)
{
	if (value < 0)
	{
		e->ret++;
		ft_putnbr(value);
	}
	else
	{
		if (e->f_positive == 1)
		{
			e->ret++;
			ft_putchar('+');
		}
		else if (e->f_positive == 0 && e->f_space == 1)
		{
			e->ret++;
			ft_putchar(' ');
		}
		ft_putnbr(value);
	}
}

static void ft_putstr_right(t_var *e, int value)
{
	if (e->f_zero == 0)
		ft_put_space(e->f_width - e->t_size, e);
	if (e->f_positive == 1)
	{
		e->ret++;
		ft_putchar('+');
	}
	if (e->f_zero == 1 && value >= 0)
		ft_put_zero(e->f_width - e->t_size, e);
	else if (e->f_zero == 1 && value < 0)
	{
		ft_putchar('-');
		ft_put_zero(e->f_width - e->t_size, e);
		value *= -1;
		e->ret++;
	}
	if (e->f_positive == 0 && e->f_space == 1)
	{
		e->ret++;
		ft_putchar(' ');
	}
	if (value < 0)
		e->ret++;
	ft_putnbr(value);
}
static int len_d(int value)
{
	int		i;

	i = 0;
	while(value != 0)
	{
		i++;
		value /= 10;
	}
	return (i);
}

void type_d(t_var *e)
{
	int		value;

	value = va_arg(e->ap, int);
	e->t_size = len_d(value);
	if (value == 0 || value < -2147483648)
		e->ret++;
	if (value < 0 && e->f_positive == 1)
		e->f_positive = 0;
	e->ret += e->t_size;
	if (e->f_precis != 0)
		e->f_zero = 1;
	if (value < 0 || e->f_positive == 1 || e->f_space == 1)
		e->t_size++;
	if (e->f_left == 1 && e->f_width == 0)
		ft_putstr_left(e, value);
	else if (e->f_left == 1 && e->f_width != 0 && e->f_width <= e->t_size)
		ft_putstr_left(e, value);
	else if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size)
	{
		ft_putstr_left(e, value);
		ft_put_space(e->f_width - e->t_size, e);
	}
	else if (e->f_left == 0 && e->f_width == 0)
		ft_putstr_left(e, value);
	else if (e->f_left == 0 && e->f_width != 0 && e->f_width <= e->t_size)
		ft_putstr_left(e, value);
	else if (e->f_left == 0 && e->f_width != 0 && e->f_width > e->t_size)
		ft_putstr_right(e, value);
}
