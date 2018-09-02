/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_length_modifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:14:16 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/14 18:12:23 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_length_modifier(const char *format, t_arg *arg)
{
	arg->type = NO_TYPE;
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			arg->type = CHAR;
		else
			arg->type = SHORT;
	}
	if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			arg->type = LONG_LONG_INT;
		else
			arg->type = LONG_INT;
	}
	if (*format == 'j')
		arg->type = M_INT;
	if (*format == 'z')
		arg->type = LONG_INT;
	if (is_length_modifier(*(format + 1)) && is_length_modifier(*format))
		return (2);
	if (is_length_modifier(*format))
		return (1);
	return (0);
}
