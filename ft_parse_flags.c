
#include "ft_printf.h"


void	ft_check_type(char *fmt, t_var *e)
{
	if (fmt[e->i] == 'c')
		type_c(e);
	else if (fmt[e->i] == 's')
		type_s(e);
	else if (fmt[e->i] == 'd' || fmt[e->i] == 'i')
		type_d(e);
	else if (fmt[e->i] == 'x'|| fmt[e->i] == 'X')
		ft_putstr("Hex mod detected");
	else if (fmt[e->i] == '%')
		type_exep(e);
	else
	{
//		e->i++;
		ft_putchar(fmt[e->i]);
		e->ret++;
	}
}

void	ft_parse_flags(char *fmt, t_var *e)
{
	ft_construct_struct(e);
	e->i++;
	flags_left(fmt, e);
	flags_positive(fmt, e);
	flags_effect(fmt, e);
	flags_zero(fmt, e);
	flags_space(fmt, e);
	flags_width(fmt, e);
	flags_precis(fmt, e);
	flags_h_l_L(fmt, e);
	if (e->error == 0)
		ft_check_type(fmt, e);
}
