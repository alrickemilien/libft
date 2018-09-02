/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:56:58 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 13:12:57 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_b(t_arg *arg)
{
	if (arg->specifier == 'b')
	{
		if (arg->type == U_INT)
			arg->str = ft_itoa_base(arg->value.ui, 2);
		else if (arg->type == U_CHAR)
			arg->str = ft_itoa_base((unsigned char)arg->value.ui, 2);
		else if (arg->type == U_SHORT)
			arg->str = ft_itoa_base((unsigned short)arg->value.ui, 2);
		else if (arg->type == U_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ul, 2);
		else if (arg->type == U_LONG_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ull, 2);
		else if (arg->type == U_INT_MAX)
			arg->str = ft_itoa_base(arg->value.uint_max, 2);
	}
}

void	set_char(t_arg *arg)
{
	if (arg->specifier == 'c' && arg->type == CHAR)
	{
		arg->str = ft_strdup("");
		if (arg->value.i)
			recycle(&arg->str, ft_char_to_str(arg->value.i));
	}
	else if (arg->specifier == 'C' || arg->specifier == 'c')
	{
		arg->str = ft_strdup("");
		if (arg->value.wi)
			recycle(&arg->str, wchar_to_str((wchar_t)arg->value.wi));
	}
	else if (arg->specifier == 's' && arg->type == A_CHAR)
	{
		arg->str = ft_strdup("(null)");
		if (arg->value.ac)
			recycle(&arg->str, ft_strdup(arg->value.ac));
	}
	else if (arg->specifier == 'S' || arg->specifier == 's')
	{
		if (arg->value.wc)
			arg->str = wstr_to_str(arg->value.wc);
		else
			arg->str = ft_strdup("(null)");
	}
}

void	set_str(t_arg *arg)
{
	set_x(arg);
	set_u(arg);
	set_d(arg);
	set_o(arg);
	set_b(arg);
	set_char(arg);
	if (arg->specifier == '%')
		arg->str = ft_strdup("%");
}
