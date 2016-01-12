/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:22:10 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/10 16:22:12 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				set_flag(const char *format, t_sys *sys, int nb) //todo : gerer override de flag
{
	int		i;

	//printf("*format = %c\n", *format);
	if ((i = get_i_prefix_flag(sys, *format)) >= 0)
	{
		sys->arg->prefix = sys->flags[i].func;
		//printf("set prefix ptr\n");
	}
	/*else if ((i = get_i_padding_flag(*format)) >= 0)
		sys_arg->padding = flags[i].func;*/
	else
		return (nb);
	sys->arg->len_arg++;
	return (set_flag(++format, sys, ++nb));
}

int				set_conv(const char *format, t_sys *sys)
{
	int		i;

	if ((i = get_i_conv(sys, *format)) < 0)
		return (-1);
	sys->arg->c = sys->conv[i].c;
	sys->arg->type = sys->conv[i].type;
	sys->arg->base = sys->conv[i].base;
	sys->arg->len_arg++;
	return (1);
	/*sys->arg->ret = (char *)malloc(sizeof(char) * 2);
	sys->arg->ret[0] = '*';
	sys->arg->ret[1] = '\0';
	sys->arg->c = 'x';
	sys->arg->len_arg++;*/
}

int				get_i_prefix_flag(t_sys *sys, char c)
{
	int		i;

	i = -1;
	while (++i < NB_FLAG)
	{
		if (sys->flags[i].c == c)
			return (i);
	}
	return (-1);
}

int				get_i_conv(t_sys *sys, char c)
{
	int		i;

	i = -1;
	while (++i < NB_CONV)
	{
		if (sys->conv[i].c == c)
			return (i);
	}
	return (-1);
}

void	prefix_hash(t_sys *sys)
{
	if (sys->arg->c == 'o')
		concat_prefix(&(sys->arg->ret), "0");
	else if (sys->arg->c == 'x')
		concat_prefix(&(sys->arg->ret), "0x");
	else if (sys->arg->c == 'X')
		concat_prefix(&(sys->arg->ret), "0X");
}
