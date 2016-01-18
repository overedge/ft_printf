/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:13:05 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/18 20:28:19 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	
	// FLAGS WIDTH
	if (e->f_width != 0 && value >= 0)
	{
		if(e->f_positive == 1)
	}
	else if (e->f_with != 0 && value < 0)
	{

	}
}
