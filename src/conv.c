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

void	ptr_flow(t_sys *sys, va_list ap)
{
	sys->arg->val.ptr = va_arg(ap, void*);
	conv_num_rec(sys, (uintmax_t)sys->arg->val.ptr, 1);
	prefix_hash(sys);
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}

void	str_flow(t_sys *sys, va_list ap)
{
	int		len_str;
	int		i;

	sys->arg->val.str = va_arg(ap, char*);
	if (sys->arg->precision > 0)
		len_str = sys->arg->precision;
	else
		len_str = ft_strlen(sys->arg->val.str);
	sys->arg->ret = (char *)malloc(sizeof(char) * (len_str + 1));
	i = -1;
	while (++i < len_str)
		sys->arg->ret[i] = sys->arg->val.str[i];
	sys->arg->ret[len_str] = '\0';
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}

void	char_flow(t_sys *sys, va_list ap)
{
	int		c;
	wchar_t	w;

	if (sys->arg->pre_len_modif == 2)
	{
		w = (wchar_t)va_arg(ap, wint_t);
		sys->arg->ret = (char *)malloc(sizeof(wchar_t) * 2);
		sys->arg->ret[0] = w;
		sys->arg->ret[1] = L'\0';
	}
	else
	{
		c = va_arg(ap, int);
		sys->arg->ret = (char *)malloc(sizeof(char) * 2);
		sys->arg->ret[0] = (unsigned char)c;
		sys->arg->ret[1] = '\0';
	}
	if (sys->arg->padding)
		sys->arg->padding->func(sys);
	else
		field(sys);
}

void	num_flow(t_sys *sys, va_list ap)
{
	sys->arg->len_modif = sys->tab_len[sys->arg->type][sys->arg->pre_len_modif];
	/*printf("******* type %d, pre mod %d, mod %d \n", sys->arg->type,
		sys->arg->pre_len_modif, sys->arg->len_modif);*/
	sys->get_arg[sys->arg->len_modif](sys, ap);
	if (sys->arg->type == NUM_U)
		conv_num_rec(sys, sys->arg->val.num_u, 1);
	else
		conv_num_rec_s(sys, sys->arg->val.num, 1, -1);
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

int		conv_num_rec_s(t_sys *sys, intmax_t num, int nb_call, int sign)
{
	int	ret;

	if (sign == -1)
	{
		if (num < 0)
		{
			sign = 1;
			num = num * -1;
		}
		else
			sign = 0;
	}

	if ((uintmax_t)num < sys->arg->base)
	{
		sys->arg->ret = (char *)malloc(sizeof(char) * (nb_call + sign + 1));
		if (sign)
			sys->arg->ret[0] = '-';
		sys->arg->ret[0 + sign] = get_char(num, sys);
		sys->arg->ret[nb_call + sign] = '\0';
		return (1);
	}
	ret = conv_num_rec_s(sys, num / sys->arg->base, ++nb_call, sign);
	sys->arg->ret[ret + sign] = get_char(num % sys->arg->base, sys);
	return (ret + 1);
}

char	get_char(int num, t_sys *sys)
{
	if (num < 10)
		return (48 + num);
	if (sys->arg->c == 'X')
		return (65 + (num - 10));
	return (97 + (num - 10));
}
