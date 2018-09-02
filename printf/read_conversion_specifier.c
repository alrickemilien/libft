/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conversion_specifier.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:15:56 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 09:25:08 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_nbr_flag(const char *format, t_arg *arg)
{
	if (*format == 'd' || *format == 'i')
	{
		if (arg->type == NO_TYPE)
			arg->type = INT;
	}
	else if (arg->type == LONG_LONG_INT)
		arg->type = U_LONG_LONG_INT;
	else if (arg->type == LONG_INT)
		arg->type = U_LONG_INT;
	else if (arg->type == CHAR)
		arg->type = U_CHAR;
	else if (arg->type == SHORT)
		arg->type = U_SHORT;
	else if (arg->type == M_INT)
		arg->type = U_INT_MAX;
	else if (arg->type == NO_TYPE)
		arg->type = U_INT;
	if (arg->precision > -1)
		arg->zero_flag = 0;
}

int			read_conversion_specifier(const char *format,
		t_arg *arg)
{
	arg->specifier = *format;
	if (*format == 'u' || *format == 'o' || *format == 'x'
		|| *format == 'X' || *format == 'd' || *format == 'i'
		|| *format == 'b')
		set_nbr_flag(format, arg);
	else if (*format == 'D')
		arg->type = LONG_INT;
	else if (*format == 'U' || *format == 'O' || *format == 'p')
		arg->type = U_LONG_INT;
	else if (*format == 'c' && arg->type == NO_TYPE)
		arg->type = CHAR;
	else if (*format == 'C' || *format == 'c')
		arg->type = WINT;
	else if (*format == 's' && arg->type == NO_TYPE)
		arg->type = A_CHAR;
	else if (*format == 'S' || *format == 's')
		arg->type = A_WCHAR;
	else if (*format == '%')
		arg->type = NO_TYPE;
	else
	{
		arg->type = NO_TYPE;
		arg->specifier = 0;
	}
	return ((int)arg->specifier);
}
