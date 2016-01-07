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
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE 1023


typedef struct	s_sys
{
	char		buff[BUFF_SIZE + 1];
	int			i_buff;
	int			b_write;
}				t_sys;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, t_sys *sys, va_list ap);
int				conversion(t_sys *sys, va_list ap);


/*
** init.c
*/
void			init_sys(t_sys *sys);

/*
** tools.c
*/
int				copy_c(t_sys *sys, char c);
int				flush_buff(t_sys *sys);

/*
** str.c
*/
size_t			ft_strlen(const char *str);

#endif
