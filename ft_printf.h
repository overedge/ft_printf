/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 16:07:37 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/19 22:56:40 by nahmed-m         ###   ########.fr       */
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
	int		f_precis;
	int		t_size;
}				t_var;

int		ft_printf(char *fmt, ...);

/*
** Flags Fuctions
*/
void	ft_parse_flags(char *fmt, t_var *e);
void	flags_left(char *fmt, t_var *e);
void	flags_positive(char *fmt, t_var *e);
void	flags_effect(char *fmt, t_var *e);
void	flags_zero(char *fmt, t_var *e);
void	flags_space(char *fmt, t_var *e);
void	flags_width(char *fmt, t_var *e);
void	flags_precis(char *fmt, t_var *e);

/*
** Type Fuctions
*/
void	ft_check_type(char *fmt, t_var *e);
void	type_d(t_var *e);
void	type_exep(t_var *e);
void	type_s(t_var *e);
void	type_c(t_var *e);
/*
** Utils Fuctions
*/
void	ft_put_space(int space);
void	ft_put_zero(int zero);
void	ft_construct_struct(t_var *e);
#endif
