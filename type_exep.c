#include "ft_printf.h"

void	type_exep(t_var *e)
{
	e->ret++;
	ft_putchar('%');
}
