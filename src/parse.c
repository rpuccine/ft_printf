/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:19:40 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/08 17:19:43 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_arg(const char *format, t_sys *sys)
{
	int		ret;

	ret = set_flag(format, sys, 0);
	format = format + ret;
	ret = set_field(format, sys);
	format = format + ret;
	ret = set_precision(format, sys);
	format = format + ret;
	if (set_conv(format, sys) < 0)
		return (-1);
	return (1);
}

void	precision(t_sys *sys)
{
	int		ret;

	if ((ret = sys->arg->precision - ft_strlen(sys->arg->ret)) <= 0)
		return ;
	prefix_with_c(&(sys->arg->ret), '0', ret);
}

void	field(t_sys *sys)
{
	int		ret;

	if ((ret = sys->arg->field - ft_strlen(sys->arg->ret)) <= 0)
		return ;
	prefix_with_c(&(sys->arg->ret), ' ', ret);
}

void	num_flow(t_sys *sys, va_list ap)
{
	sys->arg->value = va_arg(ap, int);
	conv_num_rec(sys, sys->arg->value, 1);
	precision(sys);
	if (sys->arg->sign)
		sys->arg->sign->func(sys);
	if (sys->arg->prefix)
		sys->arg->prefix->func(sys);
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}
