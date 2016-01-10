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

extern t_flag	*flags;

void	prefix_0(t_arg *sys_arg)
{
	if (sys_arg->c == 'o')
		concat_prefix(&(sys_arg->ret), "0");
	if (sys_arg->c == 'x')
		concat_prefix(&(sys_arg->ret), "0x");
	if (sys_arg->c == 'X')
		concat_prefix(&(sys_arg->ret), "0X");
}

void	init_sys_arg(t_arg *sys_arg)
{
	sys_arg->ret = NULL;
	sys_arg->type = -1;
	sys_arg->c = -1;
	sys_arg->base = -1;
	sys_arg->field = -1;
	sys_arg->precision = -1;
	sys_arg->len_arg = 1;
	sys_arg->prefix = NULL;
	sys_arg->padding = NULL;
}

int		parse_arg(const char *format, t_arg *sys_arg, t_sys *sys)
{
	init_sys_arg(sys_arg);
	set_flag(format, sys_arg);
	sys_arg->ret = "*";
	sys_arg->c = 'x';
	if (sys_arg->prefix)
	{
		sys_arg->prefix(sys_arg);
		printf("call prefix ptr\n");
	}
	copy_arg(sys_arg, sys);
	return (1);
}
