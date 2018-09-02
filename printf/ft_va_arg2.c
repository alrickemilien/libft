/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:36:08 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/12 11:36:12 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	va_arg_int(t_arg *arg, va_list ap)
{
	arg->value.i = va_arg(ap, int);
}

void	va_arg_achar(t_arg *arg, va_list ap)
{
	arg->value.ac = va_arg(ap, char*);
}

void	va_arg_double(t_arg *arg, va_list ap)
{
	arg->value.d = va_arg(ap, double);
}

void	va_arg_lint(t_arg *arg, va_list ap)
{
	arg->value.l = va_arg(ap, long int);
}

void	va_arg_llint(t_arg *arg, va_list ap)
{
	arg->value.ll = va_arg(ap, long long int);
}
