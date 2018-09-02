/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 11:34:09 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 14:06:42 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include "libft.h"

enum						e_cast
{
	INT,
	CHAR,
	DOUBLE,
	U_CHAR,
	SHORT,
	LONG_INT,
	LONG_LONG_INT,
	M_INT,
	U_INT,
	U_SHORT,
	U_LONG_INT,
	U_LONG_LONG_INT,
	U_INT_MAX,
	A_CHAR,
	WINT,
	A_WCHAR,
	NO_TYPE
};

typedef union				u_val
{
	int						i;
	wint_t					wi;
	wchar_t					*wc;
	short					sh;
	double					d;
	char					*ac;
	long int				l;
	long long int			ll;
	intmax_t				int_max;
	size_t					ui;
	unsigned char			uc;
	unsigned short			ush;
	unsigned long int		ul;
	unsigned long long int	ull;
	uintmax_t				uint_max;
}							t_val;

typedef struct				s_arg
{
	int						zero_flag;
	int						hashtag_flag;
	int						minus_flag;
	int						plus_flag;
	int						blank_flag;
	int						width;
	int						precision;
	int						offset;
	char					specifier;
	int						n;
	int						buffsize;
	int						type;
	char					*str;
	t_val					value;
}							t_arg;

int							ft_printf(const char *format, ...);
int							ft_printf_fd(int fd, const char *format, ...);
void						va_arg_achar(t_arg *arg, va_list ap);
void						va_arg_int(t_arg *arg, va_list ap);
void						va_arg_uint(t_arg *arg, va_list ap);
void						va_arg_int_max(t_arg *arg, va_list ap);
void						va_arg_uint_max(t_arg *arg, va_list ap);
void						va_arg_double(t_arg *arg, va_list ap);
void						va_arg_lint(t_arg *arg, va_list ap);
void						va_arg_llint(t_arg *arg, va_list ap);
void						va_arg_ulint(t_arg *arg, va_list ap);
void						va_arg_ullint(t_arg *arg, va_list ap);
void						va_arg_wchar(t_arg *arg, va_list ap);
void						va_arg_wint(t_arg *arg, va_list ap);
int							is_flag(char c);
int							is_conversion_specifier(char c);
int							is_length_modifier(char c);
int							push_arg(const char *format, va_list ap,
								t_list **list, void (**ft_va_arg)(
									t_arg *arg, va_list ap));
int							set_value(const char c, t_arg *arg);
void						set_str(t_arg *arg);
void						set_hexa(t_arg *arg);
void						set_blank_flag(t_arg *arg);
void						set_min_width(t_arg *arg);
void						set_precision(t_arg *arg);
void						set_buffsize(t_arg *arg);
int							read_flags(const char *format, t_arg *arg);
int							read_length_modifier(const char *format,
													t_arg *arg);
int							read_conversion_specifier(const char *format,
													t_arg *arg);
char						*ft_strdigit(char *s);
char						*wchar_to_str(wchar_t c);
char						*wstr_to_str(wchar_t *s);
void						set_x(t_arg *arg);
void						set_u(t_arg *arg);
void						set_o(t_arg *arg);
void						set_d(t_arg *arg);

#endif
