/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:45:03 by rpuccine          #+#    #+#             */
/*   Updated: 2016/01/07 15:45:06 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		copy_arg(t_sys *sys)
{
	int		i;

	i = -1;
	while (sys->arg->ret[++i])
		copy_c(sys, sys->arg->ret[i]);
	return (1);
}

int		copy_c(t_sys *sys, char c)
{
	if (sys->i_buff == BUFF_SIZE)
	{
		if (flush_buff(sys) < 0)
			return (-1);
	}
	sys->buff[sys->i_buff++] = c;
	return (1);
}

int		flush_buff(t_sys *sys)
{
	int	ret;

	sys->buff[sys->i_buff] = '\0';
	if ((ret = write(1, sys->buff, ft_strlen(sys->buff))) < 0)
		return (-1);
	sys->b_write += ret;
	sys->i_buff = 0;
	return (1);
}

int		copy_arg_w(t_sys *sys)
{
	int		i;

	printf("copy_arg_w\n");
	i = -1;
	while (sys->arg->ret_w[++i])
	{
		printf("copy_c nb : %d\n", i);
		copy_c_w(sys, sys->arg->ret_w[i]);
	}
	flush_buff_w(sys);
	return (1);
}

int		copy_c_w(t_sys *sys, wchar_t c)
{
	printf("copy_c_w i_buff_w = %d\n", sys->i_buff_w);
	if (sys->i_buff_w == BUFF_SIZE)
	{
		if (flush_buff_w(sys) < 0)
			return (-1);
	}
	sys->buff_w[sys->i_buff_w++] = c;
	return (1);
}

int		flush_buff_w(t_sys *sys)
{
	int	ret;

	printf("flush_buff_w i_buff_w = %d\n", sys->i_buff_w);
	sys->buff_w[sys->i_buff_w] = L'\0';
	if ((ret = write(1, sys->buff_w, (ft_strlen_w(sys->buff_w) * sizeof(wchar_t)))) < 0)
		return (-1);
	sys->b_write += ret;
	sys->i_buff_w = 0;
	printf("flush_buff_w ret = %d\n", ret);
	return (1);
}

int		pow_ten(int pow)
{
	if (!pow)
		return (1);
	return (10 * pow_ten(--pow));
}

int		pow_two(int pow)
{
	if (!pow)
		return (1);
	return (2 * pow_two(--pow));
}

int		is_digit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
