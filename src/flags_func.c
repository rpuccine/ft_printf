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
	if (sys->arg->c == 'x' || sys->arg->c == 'X')
	{
		if (str_cmp(sys->arg->ret, "0", 1) > 0)
			return ;
	}
	if (sys->arg->c == 'o')
		concat_prefix(&(sys->arg->ret), "0");
	else if (sys->arg->c == 'x' || sys->arg->c == 'p')
		concat_prefix(&(sys->arg->ret), "0x");
	else if (sys->arg->c == 'X')
		concat_prefix(&(sys->arg->ret), "0X");
}

void	prefix_posi_blank(t_sys *sys)
{
	if (sys->arg->type == NUM_S && sys->arg->val.num > 0)
		prefix_with_c(&(sys->arg->ret), ' ', 1);
}

void	prefix_posi_sign(t_sys *sys)
{
	if (sys->arg->type == NUM_S && sys->arg->val.num > 0)
		prefix_with_c(&(sys->arg->ret), '+', 1);
}

void	field_zero(t_sys *sys)
{
	int		ret;

	if (sys->arg->type < END_NB && sys->arg->precision != -1)
		return ;
	if ((ret = sys->arg->field - ft_strlen(sys->arg->ret)) <= 0)
		return ;
	prefix_with_c(&(sys->arg->ret), '0', ret);
	if (sys->arg->prefix && (sys->arg->c == 'x' || sys->arg->c == 'X'))
	{
		sys->arg->ret[1 + ret] = '0';
		sys->arg->ret[1] = sys->arg->c;
	}
}

void	field_neg(t_sys *sys)
{
	int		ret;

	if ((ret = sys->arg->field - ft_strlen(sys->arg->ret)) <= 0)
		return ;
	suffix_with_c(&(sys->arg->ret), ' ', ret);
}
