/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:11:54 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/12 11:12:38 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_flags(const char *format, t_arg *arg)
{
	int		i;

	i = 0;
	while (is_flag(format[i]))
	{
		if (format[i] == '#')
			arg->hashtag_flag = 1;
		if (format[i] == '-')
		{
			arg->minus_flag = 1;
			arg->zero_flag = 0;
		}
		if (format[i] == '0' && !arg->minus_flag)
			arg->zero_flag = 1;
		if (format[i] == '+')
		{
			arg->plus_flag = 1;
			arg->blank_flag = 0;
		}
		if (format[i] == ' ' && !arg->plus_flag)
			arg->blank_flag = 1;
		i++;
	}
	return (i);
}
