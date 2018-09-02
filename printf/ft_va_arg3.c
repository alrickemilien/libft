/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 08:59:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 08:59:33 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	va_arg_wchar(t_arg *arg, va_list ap)
{
	arg->value.wc = va_arg(ap, wchar_t*);
}

void	va_arg_wint(t_arg *arg, va_list ap)
{
	arg->value.wi = va_arg(ap, wint_t);
}
