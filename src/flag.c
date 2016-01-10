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

extern t_flag	*flags;

void			init_flag(void)
{
	flags = (t_flag *)malloc(sizeof(t_flag) * NB_FLAG);
	flags[0].c = '#';
	flags[0].func = prefix_0;
}

void			set_flag(const char *format, t_arg *sys_arg) //todo : override
{
	int		i;

	printf("*format = %c\n", *format);
	if ((i = get_i_prefix_flag(*format)) >= 0)
	{
		sys_arg->prefix = flags[i].func;
		printf("set prefix ptr\n");
	}
	/*else if ((i = get_i_padding_flag(*format)) >= 0)
		sys_arg->padding = flags[i].func;*/
	else
		return ;
	sys_arg->len_arg++;
	set_flag(++format, sys_arg);
}

int				get_i_prefix_flag(char c)
{
	int		i;

	i = -1;
	while (++i < NB_FLAG)
	{
		if (flags[i].c == c)
			return (i);
	}
	return (-1);
}
