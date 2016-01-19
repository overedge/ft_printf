/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:13:05 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/19 13:56:02 by nahmed-m         ###   ########.fr       */
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

static void ft_putstr_right_negativ(t_var *e, int value)
{
		e->ret++;
		ft_putchar('-');
		if (e->f_zero == 1)
			ft_put_zero(e->f_width - e->t_size);
		value *= 1;
		ft_putnbr(value);
}

static void ft_putstr_right_positiv(t_var *e, int value)
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
	if (e->f_zero == 1)
		ft_put_zero(e->f_width - e->t_size);
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
	e->ret += e->t_size;
	if (value < 0 || e->f_positive == 1 || e->f_space == 1)
		e->t_size++;

	if (e->f_left == 1 && e->f_width == 0)
		ft_putstr_left(e, value);
	else if (e->f_left == 1 && e->f_width != 0 && e->f_width <= e->t_size)
		ft_putstr_left(e, value);
	else if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size)
	{
		ft_putstr_left(e, value);
		ft_put_space(e->f_width - e->t_size);
	}
	else if (e->f_left == 0 && e->f_width == 0)
		ft_putstr_left(e, value);
	else if (e->f_left == 0 && e->f_width != 0 && e->f_width <= e->t_size)
		ft_putstr_left(e, value);
	else if (e->f_left == 0 && e->f_width != 0 && e->f_width > e->t_size && value < 0)
		ft_putstr_right_negativ(e, value);
	else if (e->f_left == 0 && e->f_width != 0 && e->f_width > e->t_size && value >= 0)
		ft_putstr_right_positiv(e, value);
}
