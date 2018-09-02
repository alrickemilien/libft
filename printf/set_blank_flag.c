/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_blank_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:40:47 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 13:35:54 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_blank_flag(t_arg *arg)
{
	if (arg->blank_flag
			&& (arg->specifier == 'i'
				|| arg->specifier == 'd'
				|| arg->specifier == 'D')
			&& arg->value.i >= 0)
		recycle(&arg->str, ft_strjoin(" ", arg->str));
}
