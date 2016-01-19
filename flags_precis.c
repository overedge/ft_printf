/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_precis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 21:35:34 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/20 00:03:59 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_precis(char *fmt, t_var *e)
{
	char			*str;
	int				i;
	
	if (fmt[e->i] == '.' && ft_isdigit(fmt[e->i + 1]))
	{
		e->i++;
		i = e->i;
		if (ft_isdigit(fmt[e->i]))
		{
			while(ft_isdigit(fmt[e->i]))
				e->i++;
			str = ft_strsub(fmt, i, e->i); 
			e->f_precis = ft_atoi(str);
			free(str);
			if (e->f_precis <= 0)
				e->f_precis = 0;
		}
	}
	else
		e->f_precis = 0;
}

