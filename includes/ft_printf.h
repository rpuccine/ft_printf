/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpuccine <rpuccine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:07:50 by rpuccine          #+#    #+#             */
/*   Updated: 2015/12/28 19:21:50 by rpuccine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_h

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 1023

/*
** ft_printf.c
*/
int		ft_printf(const char *format, ...);

#endif
