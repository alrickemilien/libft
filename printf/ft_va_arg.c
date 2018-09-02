/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:36:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 09:17:40 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	va_arg_int_max(t_arg *arg, va_list ap)
{
	arg->value.int_max = va_arg(ap, intmax_t);
}

void	va_arg_uint_max(t_arg *arg, va_list ap)
{
	arg->value.uint_max = va_arg(ap, uintmax_t);
}

void	va_arg_uint(t_arg *arg, va_list ap)
{
	arg->value.ui = va_arg(ap, unsigned int);
}

void	va_arg_ulint(t_arg *arg, va_list ap)
{
	arg->value.ul = va_arg(ap, unsigned long int);
}

void	va_arg_ullint(t_arg *arg, va_list ap)
{
	arg->value.ull = va_arg(ap, unsigned long long int);
}
