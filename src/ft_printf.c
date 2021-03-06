/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:08:03 by rpuccine          #+#    #+#             */
/*   Updated: 2015/12/28 19:49:37 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list			ap;
	static t_sys	*sys = NULL;
	int				ret;

	if (!format)
		return (-1);
	if (!sys)
	{
		if (!(sys = init_sys()))
			return (-1);
	}
	sys->b_write = 0;
	va_start(ap, format);
	ret = ft_vprintf(format, sys, ap);
	va_end(ap);
	if (ret < 0)
		return (-1);
	return (sys->b_write);
}

int			ft_vprintf(const char *format, t_sys *sys, va_list ap)
{
	int		len;

	while (*format)
	{
		if (*format != '%')
		{
			if (copy_c(sys, *format) < 0)
				return (-1);
			format++;
		}
		else
		{
			if ((len = conversion(format, sys, ap)) < 0)
				return (-1);
			format = format + len;
		}
	}
	if (flush_buff(sys) < 0)
		return (-1);
	return (1);
}

int			conversion(const char *format, t_sys *sys, va_list ap)
{
	init_sys_arg(sys);
	if (parse_arg(++format, sys) < 0)
		return (-1);
	if (sys->arg->type < END_NB)
		num_flow(sys, ap);
	else if (sys->arg->type == ESCAPE)
		escape_flow(sys);
	else if (sys->arg->type == CHARS)
	{
		if (sys->arg->pre_len_modif == 2)
			wide_char_flow(sys, ap);
		else
			char_flow(sys, ap);
	}
	else if (sys->arg->type == STR)
	{
		if (sys->arg->pre_len_modif == 2)
			wide_str_flow(sys, ap);
		else
			str_flow(sys, ap);
	}
	else if (sys->arg->type == PTR)
		ptr_flow(sys, ap);
	copy_arg(sys);
	return (sys->arg->len_arg);
}
