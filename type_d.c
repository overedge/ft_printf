
#include "ft_printf.h"

void type_d(t_var *e)
{
	int		value;

	value = va_arg(e->ap, int);
	if (value > 0 && e->f_space == 1 && e->f_positive == 0)
		ft_putchar(' ');
	ft_putnbr(value);
}
