/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:40:04 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/07 15:40:06 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

t_sys	*init_sys(void)
{
	t_sys	*sys;

	if (!(sys = (t_sys *)malloc(sizeof(t_sys))))
		return (NULL);
	sys->i_buff = 0;
	sys->b_write = 0;
	if (init_flag(sys) < 0)
		return (NULL);
	if (init_conv(sys) < 0)
		return (NULL);
	if (!(sys->arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	return (sys);
}

int		init_flag(t_sys *sys)
{
	if (!(sys->flags = (t_flag *)malloc(sizeof(t_flag) * NB_FLAG)))
		return (-1);
	sys->flags[0].c = '#';
	sys->flags[0].func = prefix_hash;
	return (1);
}

int		init_conv(t_sys *sys)
{
	if (!(sys->conv = (t_conv *)malloc(sizeof(t_conv) * NB_CONV)))
		return (-1);
	sys->conv[0].c = 'd';
	sys->conv[0].type = NUM_S;
	sys->conv[0].base = 10;
	sys->conv[1].c = 'i';
	sys->conv[1].type = NUM_S;
	sys->conv[1].base = 10;
	sys->conv[2].c = 'u';
	sys->conv[2].type = NUM_U;
	sys->conv[2].base = 10;
	sys->conv[3].c = 'o';
	sys->conv[3].type = NUM_U;
	sys->conv[3].base = 8;
	sys->conv[4].c = 'x';
	sys->conv[4].type = NUM_U;
	sys->conv[4].base = 16;
	return (1);
}

void	init_sys_arg(t_sys *sys)
{
	sys->arg->ret = NULL;
	sys->arg->type = -1;
	sys->arg->c = -1;
	sys->arg->base = -1;
	sys->arg->field = -1;
	sys->arg->precision = -1;
	sys->arg->len_arg = 1;
	sys->arg->prefix = NULL;
	sys->arg->padding = NULL;
}
