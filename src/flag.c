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

int				set_len_modif(const char *format, t_sys *sys)
{
	int		ret;

	if ((ret = str_cmp(format, "hh", 0)) > 0)
		sys->arg->pre_len_modif = 0;
	else if ((ret = str_cmp(format, "h", 0)) > 0)
		sys->arg->pre_len_modif = 1;
	else if ((ret = str_cmp(format, "ll", 0)) > 0)
		sys->arg->pre_len_modif = 3;
	else if ((ret = str_cmp(format, "l", 0)) > 0)
		sys->arg->pre_len_modif = 2;
	else if ((ret = str_cmp(format, "j", 0)) > 0)
		sys->arg->pre_len_modif = 4;
	else if ((ret = str_cmp(format, "z", 0)) > 0)
		sys->arg->pre_len_modif = 5;
	else
	{
		sys->arg->pre_len_modif = 6;
		return (0);
	}
	sys->arg->len_arg += ret;
	return (ret);
}

int				set_flag(const char *format, t_sys *sys, int nb)
{
	int		i;
	t_flag	**cur;

	if ((i = get_i_prefix_flag(sys, *format)) < 0)
		return (nb);
	sys->arg->len_arg++;
	if (sys->flags[i].type == PREFIX)
		cur = &(sys->arg->prefix);
	else if (sys->flags[i].type == PADDING)
		cur = &(sys->arg->padding);
	else
		cur = &(sys->arg->sign);
	if (!(*cur)|| sys->flags[i].prio > (*cur)->prio)
		*cur = sys->flags + i;
	return (set_flag(++format, sys, ++nb));
}

int				set_precision(const char *format, t_sys *sys)
{
	int		len;
	int		i;
	int		total;

	if (*format != '.')
		return (0);
	sys->arg->len_arg++;
	format++;
	len = get_len_field(format, sys, 0);
	total = 0;
	i = -1;
	while (++i < len)
		total += (format[i] - 48) * pow_ten(len - (i + 1));
	sys->arg->precision = total;
	if (sys->arg->padding && sys->arg->padding->prio == LOW)
		sys->arg->padding = NULL;
	return (len + 1);
}

int				set_field(const char *format, t_sys *sys)
{
	int		len;
	int		i;
	int		total;

	if (!(len = get_len_field(format, sys, 0)))
		return (0);
	total = 0;
	i = -1;
	while (++i < len)
		total += (format[i] - 48) * pow_ten(len - (i + 1));
	sys->arg->field = total;
	return (len);
}

int				get_len_field(const char *format, t_sys *sys, int nb)
{
	if (!is_digit(*format))
		return (nb);
	sys->arg->len_arg++;
	return (get_len_field(++format, sys, ++nb));
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
	if (sys->arg->c != 'X' && sys->arg->c < 97)
		sys->arg->pre_len_modif = 2;
	return (1);
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
