/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:07:37 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/14 19:47:09 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"


typedef struct	s_var
{
	va_list ap;
	int		i;
	int		ret;
	char	f_left;
	char	f_positive;
	char	f_effect;
	char	f_zero;
	char	f_space;
	int		f_width;
}				t_var;

int		ft_printf(char *fmt, ...);

/*
** Flags Fuctions
*/
void	ft_parse_flags(char *fmt, t_var *e);
void	ft_check_flags1(char *fmt, t_var *e);
void	ft_check_flags2(char *fmt, t_var *e);
void	ft_check_flags3(char *fmt, t_var *e);
void	ft_check_flags4(char *fmt, t_var *e);
void	ft_check_flags_5(char *fmt, t_var *e);
void	ft_check_flags_6(char *fmt, t_var *e);
void	ft_check_type(char *fmt, t_var *e);

/*
** Type Fuctions
*/
void	type_d(t_var *e);
#endif
