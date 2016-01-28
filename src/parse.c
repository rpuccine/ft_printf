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

int		set_escape(const char *format, t_sys *sys)
{
	if (*format != '%')
		return (0);
	sys->arg->len_arg++;
	sys->arg->type = ESCAPE;
	sys->arg->ret = (char *)malloc(sizeof(char) * 2);
	sys->arg->ret[0] = '%';
	sys->arg->ret[1] = '\0';
	return (1);
}

int		parse_arg(const char *format, t_sys *sys)
{
	int		ret;

	if (set_escape(format, sys))
		return (1);
	ret = set_flag(format, sys, 0);
	format = format + ret;
	ret = set_field(format, sys);
	format = format + ret;
	ret = set_precision(format, sys);
	format = format + ret;
	ret = set_len_modif(format, sys);
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
