/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:08:03 by rpuccine          #+#    #+#             */
/*   Updated: 2015/12/28 19:49:37 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char	buff[BUFF_SIZE];
	char	*ret_conv;

	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			*buff = *format
		}
	}
}
