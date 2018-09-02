/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:34:33 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 13:28:57 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_width(const char *format, t_arg *arg)
{
	int		i;

	i = 0;
	arg->width = ft_atoi(format);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

int			read_precision(const char *format, t_arg *arg)
{
	int		i;

	i = 0;
	arg->precision = -1;
	if (format[i] == '.')
	{
		i++;
		arg->precision = ft_atoi(format + i);
	}
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

void		arg_to_str(t_arg *arg)
{
	set_str(arg);
	set_precision(arg);
	set_buffsize(arg);
	set_blank_flag(arg);
	if (arg->str)
	{
		if (arg->width > (int)ft_strlen(arg->str))
			set_min_width(arg);
		else
		{
			set_hexa(arg);
			if (arg->plus_flag && arg->type == INT && arg->value.i >= 0)
				recycle(&arg->str, ft_strjoin("+", arg->str));
		}
		arg->buffsize += ft_strlen(arg->str);
	}
}

int			push_arg(const char *format,
		va_list ap,
		t_list **list,
		void (**ft_va_arg)(t_arg *arg, va_list ap))
{
	int		i;
	t_arg	arg;

	if (!(*format))
		return (-1);
	ft_bzero(&arg, sizeof(t_arg));
	i = read_flags(format, &arg);
	i += read_width(format + i, &arg);
	i += read_precision(format + i, &arg);
	i += read_length_modifier(format + i, &arg);
	if (!read_conversion_specifier(format + i, &arg))
		return (i);
	if (arg.specifier != '%')
		ft_va_arg[arg.type](&arg, ap);
	arg_to_str(&arg);
	ft_lstadd(list, ft_lstnew(&arg, sizeof(t_arg)));
	i += 1;
	return (i);
}
