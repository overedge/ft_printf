
#include "ft_printf.h"


void	ft_check_flags1(char *fmt, t_var *e)
{
	if (fmt[e->i] == '-')
	{
		e->f_left = 1;
		e->i++;
	}
	else
		e->f_left = 0;
}

void	ft_check_flags2(char *fmt, t_var *e)
{
	if (fmt[e->i] == '+')
	{
		e->f_positive = 1;
		e->i++;
	}
	else
		e->f_positive = 0;
}

void	ft_check_flags3(char *fmt, t_var *e)
{
	if (fmt[e->i] == '#')
	{
		e->f_effect = 1;
		e->i++;
	}
	else
		e->f_effect = 0;
}

void	ft_check_flags4(char *fmt, t_var *e)
{
	if (fmt[e->i] == '0')
	{
		e->f_zero = 1;
		e->i++;
	}
	else
		e->f_zero = 0;
}

void	ft_check_flags5(char *fmt, t_var *e)
{
	if (fmt[e->i] == ' ')
	{
		e->f_space = 1;
		e->i++;
	}
	else
		e->f_space = 0;
}

void	ft_check_flags6(char *fmt, t_var *e)
{
	char	*str;
	int		i;

	i = e->i;
	if (ft_isdigit(fmt[e->i]))
	{
		while(ft_isdigit(fmt[e->i]))
			e->i++;
		str = ft_strsub(fmt, i, e->i); 
		e->f_width = ft_atoi(str);
		free(str);
	}
	else
		e->f_width = 0;
}

void	ft_check_type(char *fmt, t_var *e)
{
	if (fmt[e->i] == 'd' || fmt[e->i] == 'i')
		type_d(e);
	else if (fmt[e->i] == 'x'|| fmt[e->i] == 'X')
		ft_putstr("Hex mod detected");
	else if (fmt[e->i] == '%')
		type_exep(e);
	else
		exit(1);
}
void	ft_parse_flags(char *fmt, t_var *e)
{
	ft_construct_struct(e);
	e->i++;
	ft_check_flags1(fmt, e);
	ft_check_flags2(fmt, e);
	ft_check_flags3(fmt, e);
	ft_check_flags4(fmt, e);
	ft_check_flags5(fmt, e);
	ft_check_flags6(fmt, e);
	ft_check_type(fmt, e);
}
