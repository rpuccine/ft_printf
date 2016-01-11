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

void	conv_num_rec(t_sys *sys, int num, int nb_call)
{
	if (num < sys->arg->base)
	{
		sys->arg->ret = (char *)malloc(sizeof(char) * (nb_call + 1));
		sys->arg->ret[nb_call - 1] = get_char(num, sys);
		sys->arg->ret[nb_call] = '\0';
		return ;
	}
	conv_num_rec(sys, num / sys->arg->base);
	sys->arg->ret[nb_call - 1] = get_char(num % sys->arg->base, sys);
}

char	get_char(int num, t_sys *sys)
{
	if (num < 10)
		return (48 + num);
	if (sys->arg->c == 'x')
		return (97 + (num - 10));
	return (65 + (num - 10));
}
