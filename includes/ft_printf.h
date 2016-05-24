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

# define NB_FLAG 5
# define NB_CONV 7
# define NB_LEN 14

/*# define NUM_U 1
# define NUM_S 2
# define CHAR 3
# define STR 4*/

struct s_sys;	// ptr_flow - wide char

typedef enum			e_bool{FALSE, TRUE} t_bool;

typedef enum			e_prio {LOW, HIGH} t_prio;

typedef enum			e_type_flag {PREFIX, PADDING, SIGN} t_type_flag;

typedef enum			e_t_arg {NUM_U, NUM_S, END_NB, ESCAPE, CHARS, STR} t_t_arg;

typedef enum			e_len {CHAR, U_CHAR, SHORT, U_SHORT, INT, U_INT, LONG, U_LONG, \
	LONG_LONG, U_LONG_LONG, INT_MAX, U_INT_MAX, SIZE_T, SSIZE_T} t_len;

typedef struct			s_val
{
	uintmax_t			num_u;
	intmax_t			num;
	char				c;
	unsigned char		c_u;
	char				*str;
}						t_val;

typedef struct			s_flag
{
	char				c;
	t_prio				prio;
	t_type_flag			type;
	void				(*func)(struct s_sys *);
}						t_flag;

typedef struct			s_arg
{
	char				*ret;
	char				c;
	t_val				val;
	t_t_arg				type;
	int					pre_len_modif;
	t_len				len_modif;
	uintmax_t			base;
	int					field;
	int					precision;
	int					len_type;
	int					len_arg;
	t_flag				*prefix;
	t_flag				*sign;
	t_flag				*padding;
	/*void		(*prefix)(struct s_sys *);
	void		(*padding)(struct s_sys *);*/
}						t_arg;

typedef struct			s_conv
{
	char				c;
	int					type;
	int					base;
}						t_conv;

typedef struct			s_sys
{
	char				buff[BUFF_SIZE + 1];
	int					i_buff;
	int					b_write;
	t_flag				*flags;
	t_conv				*conv;
	t_arg				*arg;
	void				(*get_arg[NB_LEN])(struct s_sys *, va_list);
	t_len				tab_len[2][7];
}						t_sys;

/*
** ft_printf.c
*/
int						ft_printf(const char *format, ...);
int						ft_vprintf(const char *format, t_sys *sys, va_list ap);
int						conversion(const char *format, t_sys *sys, va_list ap);


/*
** init.c
*/
void					init_tab_len(t_sys *sys);
void					init_get_arg(t_sys *sys);
t_sys					*init_sys(void);
int						init_flag(t_sys *sys);
int						init_conv(t_sys *sys);
void					init_sys_arg(t_sys *sys);

/*
** tools.c
*/
int						copy_c(t_sys *sys, char c);
int						copy_arg(t_sys *sys);
int						flush_buff(t_sys *sys);
int						pow_ten(int pow);
int						is_digit(char c);

/*
** str.c
*/
int						str_cmp(const char *str, const char *sample, int nb);
size_t					ft_strlen(const char *str);
void					prefix_with_c(char **str, char c, int nb_c);
void					suffix_with_c(char **str, char c, int nb_c);
void					concat_prefix(char **str, char *prefix);


/*
** parse.c
*/
int						set_escape(const char *format, t_sys *sys);
int						parse_arg(const char *format, t_sys *sys);
void					precision(t_sys *sys);
void					field(t_sys *sys);

/*
** flag.c
*/
int						set_len_modif(const char *format, t_sys *sys);
int						set_flag(const char *format, t_sys *sys, int nb);
int						set_precision(const char *format, t_sys *sys);
int						set_field(const char *format, t_sys *sys);
int						get_len_field(const char *format, t_sys *sys, int nb);
int						set_conv(const char *format, t_sys *sys);
int						get_i_prefix_flag(t_sys *sys, char c);
int						get_i_conv(t_sys *sys, char c);

/*
** flag_func.c
*/
void					prefix_hash(t_sys *sys);
void					prefix_posi_blank(t_sys *sys);
void					prefix_posi_sign(t_sys *sys);
void					field_zero(t_sys *sys);
void					field_neg(t_sys *sys);

/*
** conv.c
*/
void					char_flow(t_sys *sys, va_list ap);
void					str_flow(t_sys *sys, va_list ap);
void					num_flow(t_sys *sys, va_list ap);
int						conv_num_rec(t_sys *sys, uintmax_t num, int nb_call);
int						conv_num_rec_s(t_sys *sys, intmax_t num, int nb_call, int sign);
char					get_char(int num, t_sys *sys);

/*
** stdarg1.c
*/
void					get_stdarg_uchar(t_sys *sys, va_list ap);
void					get_stdarg_char(t_sys *sys, va_list ap);
void					get_stdarg_ushort(t_sys *sys, va_list ap);
void					get_stdarg_short(t_sys *sys, va_list ap);
void					get_stdarg_uint(t_sys *sys, va_list ap);
void					get_stdarg_int(t_sys *sys, va_list ap);
void					get_stdarg_ulong(t_sys *sys, va_list ap);
void					get_stdarg_long(t_sys *sys, va_list ap);
void					get_stdarg_ulonglong(t_sys *sys, va_list ap);
void					get_stdarg_longlong(t_sys *sys, va_list ap);
void					get_stdarg_intmax(t_sys *sys, va_list ap);
void					get_stdarg_uintmax(t_sys *sys, va_list ap);
void					get_stdarg_sizet(t_sys *sys, va_list ap);
void					get_stdarg_ssizet(t_sys *sys, va_list ap);

#endif
