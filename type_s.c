/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <nahmed-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 22:20:22 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/19 23:01:31 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_s(t_var *e)
{
	char *str;

	str = ft_strdup(va_arg(e->ap, char*));
	ft_putstr(str);
	e->ret += ft_strlen(str);
	free(str);
}
