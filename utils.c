/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 11:10:03 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/19 11:15:29 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_space(int space)
{
	int		i;

	i = 0;
	while (i < space)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_put_zero(int zero)
{
	int		i;

	i = 0;
	while (i < zero)
	{
		ft_putchar('0');
		i++;
	}
}
