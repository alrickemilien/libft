/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 09:20:04 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 09:21:35 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_x(t_arg *arg)
{
	if (arg->specifier == 'x' || arg->specifier == 'X')
	{
		if (arg->type == U_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ul, 16);
		else if (arg->type == U_LONG_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ull, 16);
		else if (arg->type == U_INT)
			arg->str = ft_itoa_base(arg->value.ui, 16);
		else if (arg->type == U_SHORT)
			arg->str = ft_itoa_base((unsigned short)arg->value.ui, 16);
		else if (arg->type == U_CHAR)
			arg->str = ft_itoa_base((unsigned char)arg->value.ui, 16);
		else if (arg->type == U_INT_MAX)
			arg->str = ft_itoa_base(arg->value.uint_max, 16);
	}
	else if (arg->specifier == 'p')
		arg->str = ft_itoa_base(arg->value.ul, 16);
	if (arg->specifier == 'X')
		recycle(&arg->str, ft_strupcase(arg->str));
}

void	set_d(t_arg *arg)
{
	if (arg->specifier == 'd' || arg->specifier == 'i' || arg->specifier == 'D')
	{
		if (arg->type == INT)
			arg->str = ft_itoa(arg->value.i);
		else if (arg->type == SHORT)
			arg->str = ft_itoa((short)arg->value.i);
		else if (arg->type == CHAR)
			arg->str = ft_itoa((char)arg->value.i);
		else if (arg->type == M_INT)
			arg->str = ft_itoa((intmax_t)arg->value.int_max);
		else if (arg->type == LONG_INT)
			arg->str = ft_itoa((long)arg->value.l);
		else if (arg->type == U_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ul, 10);
		else if (arg->type == LONG_LONG_INT)
			arg->str = ft_itoa((long long)arg->value.ll);
	}
}

void	set_o(t_arg *arg)
{
	if (arg->specifier == 'o' || arg->specifier == 'O')
	{
		if (arg->type == U_INT)
			arg->str = ft_itoa_base(arg->value.ui, 8);
		else if (arg->type == U_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ul, 8);
		else if (arg->type == U_LONG_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ull, 8);
		else if (arg->type == U_SHORT)
			arg->str = ft_itoa_base((unsigned short)arg->value.ui, 8);
		else if (arg->type == U_CHAR)
			arg->str = ft_itoa_base((unsigned char)arg->value.ui, 8);
		else if (arg->type == U_INT_MAX)
			arg->str = ft_itoa_base(arg->value.uint_max, 8);
	}
}

void	set_u(t_arg *arg)
{
	if (arg->specifier == 'u' || arg->specifier == 'U')
	{
		if (arg->type == U_INT)
			arg->str = ft_itoa_base(arg->value.ui, 10);
		else if (arg->type == U_CHAR)
			arg->str = ft_itoa_base((unsigned char)arg->value.ui, 10);
		else if (arg->type == U_SHORT)
			arg->str = ft_itoa_base((unsigned short)arg->value.ui, 10);
		else if (arg->type == U_LONG_INT)
			arg->str = ft_itoa_base((unsigned long)arg->value.ul, 10);
		else if (arg->type == U_LONG_LONG_INT)
			arg->str = ft_itoa_base(arg->value.ull, 10);
		else if (arg->type == U_INT_MAX)
			arg->str = ft_itoa_base(arg->value.uint_max, 10);
	}
}
