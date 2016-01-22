/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:13:05 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/22 19:00:59 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putstr_left(t_var *e, long long int value)
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

static void ft_putstr_right(t_var *e, long long int value)
{
	if (e->f_zero == 0)
		ft_put_space(e->f_width - e->t_size, e);
	if (e->f_positive == 1)
	{
		e->ret++;
		ft_putchar('+');
	}
	if (e->f_zero == 1 && value < 0)
	{
		ft_putchar('-');
		ft_put_zero(e->f_width - e->t_size, e);
		value *= -1;
		e->ret++;
	}
	else if (e->f_zero == 1)
		ft_put_zero(e->f_width - e->t_size, e);
	if (e->f_positive == 0 && e->f_space == 1 && e->f_precis == 0)
	{
		e->ret++;
		ft_putchar(' ');
	}
	if (value < 0)
		e->ret++;
	ft_putnbr(value);
}
static int len_d(long long int value)
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
	long long int		value;

	value = va_arg(e->ap, long long int);
	e->t_size = len_d(value);
	if (value == 0 || value < -2147483648 )
		e->ret++;
	if ((value == 32768 && e->f_h == 1) || (value == 128 && e->f_hh == 1))
	{
		ft_putchar('-');
		e->ret++;
	}
	if (value < 0 && e->f_positive == 1)
		e->f_positive = 0;
	e->ret += e->t_size;
	if (value < 0 || e->f_positive == 1 || e->f_space == 1)
		e->t_size++;
	if (e->f_left == 1 && e->f_width != 0 && e->f_width > e->t_size)
	{
		ft_putstr_left(e, value);
		ft_put_space(e->f_width - e->t_size, e);
	}
	else if (e->f_left == 0 && e->f_width != 0 && e->f_width > e->t_size)
		ft_putstr_right(e, value);
	else
		ft_putstr_left(e, value);
}
