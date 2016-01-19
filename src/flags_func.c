/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 18:37:02 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/19 18:37:05 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prefix_hash(t_sys *sys)
{
	if (sys->arg->c == 'o')
		concat_prefix(&(sys->arg->ret), "0");
	else if (sys->arg->c == 'x')
		concat_prefix(&(sys->arg->ret), "0x");
	else if (sys->arg->c == 'X')
		concat_prefix(&(sys->arg->ret), "0X");
}

void	prefix_posi_blank(t_sys *sys)
{
	if (sys->arg->type == NUM_S && sys->arg->value > 0)
		prefix_with_c(&(sys->arg->ret), ' ', 1);
}

void	prefix_posi_sign(t_sys *sys)
{
	if (sys->arg->type == NUM_S && sys->arg->value > 0)
		prefix_with_c(&(sys->arg->ret), '+', 1);
}
