/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:22:44 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/25 02:41:40 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <unistd.h>


void	ft_putwchar(unsigned short int str)
{
	write(1 , &str, sizeof(wchar_t));
}

int main()
{
	ft_putwchar(L'中');
	return (0);
}
