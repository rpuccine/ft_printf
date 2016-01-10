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

t_flag		*flags = NULL;

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_sys	sys;
	int		ret;

	if (!format)
		return (-1);
	if (!flags)
		init_flag();
	init_sys(&sys);
	va_start(ap, format);
	ret = ft_vprintf(format, &sys, ap);
	va_end(ap);
	if (ret < 0)
		return (-1);
	return (sys.b_write);
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
	t_arg	sys_arg;

	(void) ap;
	parse_arg(++format, &sys_arg, sys);
	return (sys_arg.len_arg);
	/*if (sys_arg.type < CHAR)
		return (num_flow(&sys_arg, sys, ap));
	return (str_flow(&sys_arg, sys, ap));*/
}
