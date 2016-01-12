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

int		conv_num_rec(t_sys *sys, int num, int nb_call)
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
