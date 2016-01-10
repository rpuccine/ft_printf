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

# include <stdio.h>

# define BUFF_SIZE 1023
# define NB_FLAG 1
# define NUM_U 1
# define NUM_S 2
# define CHAR 3
# define STR 4

typedef struct	s_sys
{
	char		buff[BUFF_SIZE + 1];
	int			i_buff;
	int			b_write;
}				t_sys;

typedef struct	s_arg
{
	char		*ret;
	int			type;
	char		c;
	int			base;
	int			field;
	int			precision;
	int			len_arg;
	void		(*prefix)(struct s_arg *);
	void		(*padding)(struct s_arg *);
}				t_arg;

typedef struct	s_flag
{
	char		c;
	void		(*func)(t_arg *);
}				t_flag;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, t_sys *sys, va_list ap);
int				conversion(const char *format, t_sys *sys, va_list ap);


/*
** init.c
*/
void			init_sys(t_sys *sys);

/*
** tools.c
*/
int				copy_c(t_sys *sys, char c);
int				flush_buff(t_sys *sys);
int				copy_arg(t_arg *sys_arg, t_sys *sys);

/*
** str.c
*/
size_t			ft_strlen(const char *str);
void			concat_prefix(char **str, char *prefix);

/*
** parse.c
*/
void			prefix_0(t_arg *sys_arg);
void			init_sys_arg(t_arg *sys_arg);
int				parse_arg(const char *format, t_arg *sys_arg, t_sys *sys);

/*
** flag.c
*/
void			init_flag(void);
void			set_flag(const char *format, t_arg *sys_arg);
int				get_i_prefix_flag(char c);

#endif
