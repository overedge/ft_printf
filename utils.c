/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:10:03 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/21 20:54:45 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_space(int space, t_var *e)
{
	int		i;

	i = 0;
	while (i < space)
	{
		ft_putchar(' ');
		e->ret++;
		i++;
	}
}

void	ft_put_zero(int zero, t_var *e)
{
	int		i;

	i = 0;
	while (i < zero)
	{
		ft_putchar('0');
		e->ret++;
		i++;
	}
}

void	ft_construct_struct(t_var *e)
{
	e->error = 0;
	e->f_left = 0;
	e->f_positive = 0;
	e->f_effect = 0;
	e->f_zero = 0;
	e->f_space = 0;
	e->f_width = 0;
	e->f_precis = 0;
	e->t_size = 0;
	e->f_hh = 0;
	e->f_h = 0;
	e->f_ll = 0;
	e->f_j = 0;
	e->f_z = 0;
}
