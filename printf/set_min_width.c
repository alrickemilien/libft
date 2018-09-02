/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_min_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 09:16:45 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 14:22:42 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_minus_flag(t_arg *arg)
{
	char		*t;

	t = NULL;
	if (arg->specifier == 'c' && !arg->value.i)
		recycle(&arg->str, ft_strjoin(arg->str, (t = ft_strrepeat(" ",
					arg->width - 1))));
	else
		recycle(&arg->str, ft_strjoin(arg->str, (t = ft_strrepeat(" ",
					arg->width - ft_strlen(arg->str)))));
	if (t)
		free(t);
}

static void		fill_blanks(t_arg *arg)
{
	char		*t;

	t = NULL;
	if (arg->specifier == 'c' && !arg->value.i)
		recycle(&arg->str, ft_strjoin(
					(t = ft_strrepeat(" ", arg->width - 1)), arg->str));
	else
		recycle(&arg->str, ft_strjoin((t = ft_strrepeat(" ",
					arg->width - (int)ft_strlen(arg->str))), arg->str));
	if (t)
		free(t);
}

static int		blank_flag(t_arg *arg)
{
	if (arg->blank_flag
			&& (arg->specifier == 'd'
				|| arg->specifier == 'D'
				|| arg->specifier == 'i')
			&& arg->value.i >= 0)
	{
		recycle(&arg->str, ft_strjoin(
					ft_strrepeat("0", arg->width - ft_strlen(arg->str)),
					ft_strchr(arg->str, ' ') + 1));
		recycle(&arg->str, ft_strjoin(" ", arg->str));
		return (1);
	}
	return (0);
}

static void		fill_zero(t_arg *arg, char *t)
{
	if (arg->type == INT && arg->value.i < 0)
	{
		recycle(&arg->str, ft_strjoin(
					(t = ft_strrepeat("0", arg->width - ft_strlen(arg->str))),
					ft_strchr(arg->str, '-') + 1));
		recycle(&arg->str, ft_strjoin("-", arg->str));
	}
	else if (blank_flag(arg))
		return ;
	else if ((arg->hashtag_flag && (arg->specifier == 'x'
			|| arg->specifier == 'X')) || arg->specifier == 'p')
		recycle(&arg->str, ft_strsplice(arg->str,
				(t = ft_strrepeat("0", arg->width - ft_strlen(arg->str))), 2));
	else if (arg->plus_flag && arg->type == INT && arg->value.i >= 0)
		recycle(&arg->str, ft_strsplice(arg->str,
				(t = ft_strrepeat("0", arg->width - ft_strlen(arg->str))), 1));
	else if (arg->specifier == 'c' && !arg->value.i)
		recycle(&arg->str, ft_strjoin(
					(t = ft_strrepeat("0", arg->width - 1)), arg->str));
	else
		recycle(&arg->str, ft_strjoin((t = ft_strrepeat(
				"0", arg->width - ft_strlen(arg->str))), arg->str));
	if (t)
		free(t);
}

void			set_min_width(t_arg *arg)
{
	char	*t;

	t = NULL;
	set_hexa(arg);
	if (arg->plus_flag && arg->type == INT && arg->value.i >= 0)
		recycle(&arg->str, ft_strjoin("+", arg->str));
	if (arg->minus_flag)
		return (set_minus_flag(arg));
	if (!arg->zero_flag)
		fill_blanks(arg);
	else
		fill_zero(arg, t);
}
