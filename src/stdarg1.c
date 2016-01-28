/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdarg1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:24:38 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/28 16:24:41 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_stdarg_uchar(t_sys *sys, va_list ap)
{
	sys->arg->val.t_u_hh = (unsigned char)va_arg(ap, int);
}

void	get_stdarg_char(t_sys *sys, va_list ap)
{
	sys->arg->val.t_hh = (char)va_arg(ap, int);
}

void	get_stdarg_ushort(t_sys *sys, va_list ap)
{
	sys->arg->val.t_u_h = (unsigned short)va_arg(ap, int);
}

void	get_stdarg_short(t_sys *sys, va_list ap)
{
	sys->arg->val.t_h = (short)va_arg(ap, int);
}

void	get_stdarg_int(t_sys *sys, va_list ap)
{
	sys->arg->val.t_int = va_arg(ap, int);
}

void	get_stdarg_ulong(t_sys *sys, va_list ap)
{
	sys->arg->val.t_u_l = va_arg(ap, unsigned long);
}

void	get_stdarg_long(t_sys *sys, va_list ap)
{
	sys->arg->val.t_l = va_arg(ap, long);
}

void	get_stdarg_ulonglong(t_sys *sys, va_list ap)
{
	sys->arg->val.t_u_ll = va_arg(ap, unsigned long long);
}

void	get_stdarg_longlong(t_sys *sys, va_list ap)
{
	sys->arg->val.t_ll = va_arg(ap, long long);
}

void	get_stdarg_sizet(t_sys *sys, va_list ap)
{
	sys->arg->val.t_u_z = va_arg(ap, size_t);
}

void	get_stdarg_ssizet(t_sys *sys, va_list ap)
{
	sys->arg->val.t_z = va_arg(ap, ssize_t);
}

void	get_stdarg_uintmax(t_sys *sys, va_list ap)
{
	sys->arg->val.t_u_j = va_arg(ap, uintmax_t);
}

void	get_stdarg_intmax(t_sys *sys, va_list ap)
{
	sys->arg->val.t_j = va_arg(ap, intmax_t);
}
