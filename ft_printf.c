/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:07:08 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/21 00:47:02 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
void	debug(t_var *e)
{
	if (e->f_left == 1)
		ft_putstr("- Flags Actived \n");
	else
		ft_putstr("- Flags Not Actived \n");
	if (e->f_positive == 1)
		ft_putstr("+ Flags Actived \n");
	else
		ft_putstr("+ Flags Not Actived \n");
	if (e->f_effect == 1)
		ft_putstr("# Flags Actived \n");
	else
		ft_putstr("# Flags Not Actived \n");
	if (e->f_zero == 1)
		ft_putstr("0 Flags Actived \n");
	else
		ft_putstr("0 Flags Not Actived \n");
	if (e->f_space == 1)
		ft_putstr("' ' Flags Actived \n");
	else
		ft_putstr("' 'Flags Not Actived \n");
	if (e->f_width != 0)
		ft_putstr("width Flags Actived\n");
	else
		ft_putstr("width Flags Not Actived \n");
	if (e->f_precis != 0)
		ft_putstr("Precision Flags Actived\n");
	else
		ft_putstr("Precision Flags Not Actived \n");
}*/

int		ft_printf(char *fmt, ...)
{
	t_var e;

	e.i = 0;
	e.ret = 0;
	e.error = 0;
	if (fmt)
		va_start(e.ap, fmt);
	while(fmt[e.i] && fmt)
	{
		if (fmt[e.i] == '%' && fmt[e.i + 1] != '\0')
		{
			ft_parse_flags(fmt, &e);
		//	debug(&e);
		}
		else if (e.error != 0)
			e.ret--;
		else if (fmt[e.i] == '%' && fmt[e.i + 1] == '\0')
			e.ret = e.ret;
		else
		{
			ft_putchar(fmt[e.i]);
			e.ret++;
		}
		e.i++;
	}
	va_end(e.ap);
	return (e.ret);
}
