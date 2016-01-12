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
# define NB_CONV 5
# define NUM_U 1
# define NUM_S 2
# define CHAR 3
# define STR 4

struct s_sys; // sortir du parse arg le flow set_conv, bien gerer le flow

typedef struct	s_arg
{
	char		*ret;
	char		c;
	int			type;
	int			base;
	int			field;
	int			precision;
	int			len_type;
	int			len_arg;
	void		(*prefix)(struct s_sys *);
	void		(*padding)(struct s_sys *);
}				t_arg;

typedef struct	s_flag
{
	char		c;
	void		(*func)(struct s_sys *);
}				t_flag;

typedef struct	s_conv
{
	char		c;
	int			type;
	int			base;
}				t_conv;

typedef struct	s_sys
{
	char		buff[BUFF_SIZE + 1];
	int			i_buff;
	int			b_write;
	t_flag		*flags;
	t_conv		*conv;
	t_arg		*arg;
}				t_sys;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, t_sys *sys, va_list ap);
int				conversion(const char *format, t_sys *sys, va_list ap);


/*
** init.c
*/
t_sys			*init_sys(void);
int				init_flag(t_sys *sys);
int				init_conv(t_sys *sys);
void			init_sys_arg(t_sys *sys);

/*
** tools.c
*/
int				copy_c(t_sys *sys, char c);
int				flush_buff(t_sys *sys);
int				copy_arg(t_sys *sys);

/*
** str.c
*/
size_t			ft_strlen(const char *str);
void			concat_prefix(char **str, char *prefix);

/*
** parse.c
*/
int				parse_arg(const char *format, t_sys *sys);

/*
** flag.c
*/
void			prefix_hash(t_sys *sys);
int				set_flag(const char *format, t_sys *sys, int nb);
int				set_conv(const char *format, t_sys *sys);
int				get_i_prefix_flag(t_sys *sys, char c);
int				get_i_conv(t_sys *sys, char c);

/*
** conv.c
*/
int				conv_num_rec(t_sys *sys, int num, int nb_call);
char			get_char(int num, t_sys *sys);

#endif
