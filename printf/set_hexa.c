/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 20:02:32 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/15 11:38:07 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_hexa(t_arg *arg)
{
	if (arg->hashtag_flag && arg->specifier == 'x'
			&& ft_strcmp(arg->str, "0") && ft_strcmp(arg->str, ""))
		recycle(&arg->str, ft_strjoin("0x", arg->str));
	if (arg->specifier == 'p'
			&& (arg->precision < 0 || ft_strcmp(arg->str, "0")))
		recycle(&arg->str, ft_strjoin("0x", arg->str));
	if (arg->hashtag_flag && arg->specifier == 'b'
		&& (arg->precision < 0 || ft_strcmp(arg->str, "0")))
		recycle(&arg->str, ft_strjoin("b", arg->str));
	if (arg->hashtag_flag && arg->specifier == 'X' && ft_strcmp(arg->str, "0"))
		recycle(&arg->str, ft_strjoin("0X", arg->str));
	if (arg->hashtag_flag
		&& (arg->specifier == 'o' || arg->specifier == 'O'))
	{
		if ((int)ft_strlen(arg->str) == arg->precision)
			arg->precision++;
		if (arg->str[0] != '0')
			recycle(&arg->str, ft_strjoin("0", arg->str));
	}
}
