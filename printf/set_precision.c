/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 08:56:46 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 08:53:38 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_nbr_precision(t_arg *arg)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(arg->str, '-')
		&& arg->precision > (int)ft_strlen(arg->str) - 1)
	{
		recycle(&arg->str, ft_strjoin((tmp = ft_strrepeat("0",
					arg->precision - ft_strlen(arg->str) + 1)),
					ft_strchr(arg->str, '-') + 1));
		recycle(&arg->str, ft_strjoin("-", arg->str));
	}
	else if (!arg->precision && !ft_strcmp(arg->str, "0")
			&& (arg->specifier == 'x' || arg->specifier == 'X'
				|| arg->specifier == 'O' || arg->specifier == 'o'
				|| arg->specifier == 'd' || arg->specifier == 'i'
				|| arg->specifier == 'D' || arg->specifier == 'u'
				|| arg->specifier == 'U' || arg->specifier == 'p'))
		recycle(&arg->str, ft_strdup(""));
	else if (arg->precision > (int)ft_strlen(arg->str))
		recycle(&arg->str,
			ft_strjoin((tmp = ft_strrepeat("0",
			arg->precision - ft_strlen(arg->str))), arg->str));
	if (tmp)
		free(tmp);
}

void	set_precision(t_arg *arg)
{
	if (arg->precision < 0 || arg->specifier == 'c'
		|| arg->specifier == '%' || arg->specifier == 'C')
		return ;
	if (arg->specifier != 's' && arg->specifier != 'S')
		set_nbr_precision(arg);
	else if (arg->precision < (int)ft_strlen(arg->str))
		recycle(&arg->str, ft_strsub(arg->str, 0, arg->precision));
}
