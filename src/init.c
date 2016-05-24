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
	init_get_arg(sys);
	init_tab_len(sys);
	if (!(sys->arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	return (sys);
}

void	init_get_arg(t_sys *sys)
{
	sys->get_arg[CHAR] = get_stdarg_char;
	sys->get_arg[U_CHAR] = get_stdarg_uchar;
	sys->get_arg[SHORT] = get_stdarg_short;
	sys->get_arg[U_SHORT] = get_stdarg_ushort;
	sys->get_arg[INT] = get_stdarg_int;
	sys->get_arg[U_INT] = get_stdarg_uint;
	sys->get_arg[LONG] = get_stdarg_long;
	sys->get_arg[U_LONG] = get_stdarg_ulong;
	sys->get_arg[LONG_LONG] = get_stdarg_longlong;
	sys->get_arg[U_LONG_LONG] = get_stdarg_ulonglong;
	sys->get_arg[INT_MAX] = get_stdarg_intmax;
	sys->get_arg[U_INT_MAX] = get_stdarg_uintmax;
	sys->get_arg[SIZE_T] = get_stdarg_sizet;
	sys->get_arg[SSIZE_T] = get_stdarg_ssizet;
}

void	init_tab_len(t_sys *sys)
{
	sys->tab_len[0][0] = U_CHAR;
	sys->tab_len[0][1] = U_SHORT;
	sys->tab_len[0][2] = U_LONG;
	sys->tab_len[0][3] = U_LONG_LONG;
	sys->tab_len[0][4] = U_INT_MAX;
	sys->tab_len[0][5] = SIZE_T;
	sys->tab_len[0][6] = U_INT;
	sys->tab_len[1][0] = CHAR;
	sys->tab_len[1][1] = SHORT;
	sys->tab_len[1][2] = LONG;
	sys->tab_len[1][3] = LONG_LONG;
	sys->tab_len[1][4] = INT_MAX;
	sys->tab_len[1][5] = SSIZE_T;
	sys->tab_len[1][6] = INT;
}

int		init_flag(t_sys *sys)
{
	if (!(sys->flags = (t_flag *)malloc(sizeof(t_flag) * NB_FLAG)))
		return (-1);
	sys->flags[0].c = '#';
	sys->flags[0].prio = HIGH;
	sys->flags[0].type = PREFIX;
	sys->flags[0].func = prefix_hash;
	sys->flags[1].c = ' ';
	sys->flags[1].prio = LOW;
	sys->flags[1].type = SIGN;
	sys->flags[1].func = prefix_posi_blank;
	sys->flags[2].c = '+';
	sys->flags[2].prio = HIGH;
	sys->flags[2].type = SIGN;
	sys->flags[2].func = prefix_posi_sign;
	sys->flags[3].c = '0';
	sys->flags[3].prio = LOW;
	sys->flags[3].type = PADDING;
	sys->flags[3].func = field_zero;
	sys->flags[4].c = '-';
	sys->flags[4].prio = HIGH;
	sys->flags[4].type = PADDING;
	sys->flags[4].func = field_neg;
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
	sys->conv[5].c = 'c';
	sys->conv[5].type = CHARS;
	sys->conv[5].base = -1;
	sys->conv[6].c = 's';
	sys->conv[6].type = STR;
	sys->conv[6].base = -1;
	return (1);
}

void	init_sys_arg(t_sys *sys)
{
	sys->arg->ret = NULL;
	sys->arg->c = -1;
	sys->arg->val.num_u = 0;
	sys->arg->val.num = 0;
	sys->arg->val.c = 0;
	sys->arg->val.c_u = 0;
	sys->arg->val.str = NULL;
	sys->arg->type = -1;
	sys->arg->len_modif = INT;
	sys->arg->base = 0;
	sys->arg->field = -1;
	sys->arg->precision = -1;
	sys->arg->len_type = 4;
	sys->arg->len_arg = 1;
	sys->arg->prefix = NULL;
	sys->arg->padding = NULL;
	sys->arg->sign = NULL;
}
