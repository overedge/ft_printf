/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 22:43:12 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/21 19:28:14 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putstr_left(char c, t_var *e)
{
	ft_putchar(c);
	e->ret++;
	ft_put_space(e->f_width - 1, e);
}

static void ft_putstr_right(char c, t_var *e)
{
	if (e->f_zero == 0)
		ft_put_space(e->f_width - 1, e);
	else
		ft_put_zero(e->f_width - 1, e);
	ft_putchar(c);
	e->ret++;
}
void	type_c(t_var *e)
{
	char c;

	c = va_arg(e->ap, int);
	if (e->f_width == 0)
	{
		ft_putchar(c);
		e->ret++;
		return ;
	}
	else if (e->f_width != 0 && e->f_left == 1)
		ft_putstr_left(c, e);
	else if (e->f_width != 0 && e->f_left == 0)
		ft_putstr_right(c, e);
}
