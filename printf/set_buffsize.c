/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_buffsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:30:24 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/15 11:39:20 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_buffsize(t_arg *arg)
{
	arg->buffsize = 0;
	if ((arg->specifier == 'c' && !arg->value.i)
		|| (!arg->value.wi && arg->specifier == 'C'))
		arg->buffsize = 1;
}
