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
	/*sys_arg->ret = "*";
	sys_arg->c = 'x';*/
	if (set_conv(format, sys) < 0)
		return (-1);
	conv_num_rec(sys, 31, 1);
	if (sys->arg->prefix)
	{
		sys->arg->prefix(sys);
		//printf("call prefix ptr\n");
	}
	copy_arg(sys);
	return (1);
}
