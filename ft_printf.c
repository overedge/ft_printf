/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:07:08 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/19 13:59:35 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
}

int		ft_printf(char *fmt, ...)
{
	t_var e;

	e.i = 0;
	e.ret = 0;
	va_start(e.ap, fmt);
	while(fmt[e.i])
	{
		 if (fmt[e.i] == '%')
		{
			ft_parse_flags(fmt, &e);
//			debug(&e);
		}
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
