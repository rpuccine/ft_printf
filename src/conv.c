/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 16:46:18 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/11 16:46:20 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_flow(t_sys *sys, va_list ap)
{
	int		len_str;
	int		i;

	sys->arg->val.t_str = va_arg(ap, char*);
	if (sys->arg->precision > 0)
		len_str = sys->arg->precision;
	else
		len_str = ft_strlen(sys->arg->val.t_str);
	sys->arg->ret = (char *)malloc(sizeof(char) * (len_str + 1));
	i = -1;
	while (++i < len_str)
		sys->arg->ret[i] = sys->arg->val.t_str[i];
	sys->arg->ret[len_str] = '\0';
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}

void	char_flow(t_sys *sys, va_list ap)
{
	sys->arg->val.t_int = va_arg(ap, int);
	sys->arg->ret = (char *)malloc(sizeof(char) * 2);
	sys->arg->ret[0] = (unsigned char)sys->arg->val.t_int;
	sys->arg->ret[1] = '\0';
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}

void	num_flow(t_sys *sys, va_list ap)
{
	sys->arg->len_modif = sys->tab_len[sys->arg->type][sys->arg->pre_len_modif];
	printf("******* arg t %d, pre mod %d, mod %d \n", sys->arg->type,
		sys->arg->pre_len_modif, sys->arg->len_modif);
	sys->get_arg[sys->arg->len_modif](sys, ap);
	conv_num_rec(sys, sys->arg->val.t_u_j, 1);
	precision(sys);
	if (sys->arg->sign)
		sys->arg->sign->func(sys);
	if (sys->arg->prefix)
		sys->arg->prefix->func(sys);
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}

int		conv_num_rec(t_sys *sys, uintmax_t num, int nb_call)
{
	int	ret;

	if (num < sys->arg->base)
	{
		sys->arg->ret = (char *)malloc(sizeof(char) * (nb_call + 1));
		sys->arg->ret[0] = get_char(num, sys);
		sys->arg->ret[nb_call] = '\0';
		return (1);
	}
	ret = conv_num_rec(sys, num / sys->arg->base, ++nb_call);
	sys->arg->ret[ret] = get_char(num % sys->arg->base, sys);
	return (ret + 1);
}

char	get_char(int num, t_sys *sys)
{
	if (num < 10)
		return (48 + num);
	if (sys->arg->c == 'x')
		return (97 + (num - 10));
	return (65 + (num - 10));
}
