/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 20:35:32 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/19 20:36:40 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_zero(char *fmt, t_var *e)
{
	if (fmt[e->i] == '0')
	{
		e->f_zero = 1;
		e->i++;
	}
	else
		e->f_zero = 0;
}
