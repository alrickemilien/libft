/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:03:40 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 14:16:14 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		del(void *data, size_t size)
{
	(void)size;
	if (((t_arg*)data)->str)
		free(((t_arg*)data)->str);
	free(data);
}

static void		init_tab(void (**ft_va_arg)(t_arg *arg, va_list ap))
{
	ft_va_arg[INT] = &va_arg_int;
	ft_va_arg[WINT] = &va_arg_wint;
	ft_va_arg[A_WCHAR] = &va_arg_wchar;
	ft_va_arg[M_INT] = &va_arg_int_max;
	ft_va_arg[U_INT_MAX] = &va_arg_uint_max;
	ft_va_arg[SHORT] = &va_arg_int;
	ft_va_arg[CHAR] = &va_arg_int;
	ft_va_arg[U_CHAR] = &va_arg_uint;
	ft_va_arg[DOUBLE] = &va_arg_double;
	ft_va_arg[U_SHORT] = &va_arg_uint;
	ft_va_arg[A_CHAR] = &va_arg_achar;
	ft_va_arg[U_INT] = &va_arg_uint;
	ft_va_arg[LONG_INT] = &va_arg_lint;
	ft_va_arg[LONG_LONG_INT] = &va_arg_llint;
	ft_va_arg[U_LONG_INT] = &va_arg_ulint;
	ft_va_arg[U_LONG_LONG_INT] = &va_arg_ullint;
}

static int		get_next_arg(const char *format,
						va_list ap,
						t_list **list,
						void (**ft_va_arg)(t_arg *arg, va_list ap))
{
	int			i;
	t_arg		arg;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			break ;
		i++;
	}
	if (i && format[i] == '%')
	{
		arg.str = ft_strsub(format, 0, i);
		arg.buffsize = i;
		ft_lstadd(list, ft_lstnew(&arg, sizeof(t_arg)));
	}
	else if (i)
	{
		arg.str = ft_strsub(format, 0, i);
		arg.buffsize = i;
		ft_lstadd(list, ft_lstnew(&arg, sizeof(t_arg)));
	}
	else if (format[i] == '%')
		i += push_arg(format + 1, ap, list, ft_va_arg) + 1;
	return (i);
}

void			set_buffer(t_list *list, int *n)
{
	while (list)
	{
		if (((t_arg*)list->content)->str)
			ft_putstr(((t_arg*)list->content)->str);
		*n += ((t_arg*)list->content)->buffsize;
		list = list->next;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;
	t_list		*list;
	int			n;
	void		(*ft_va_arg[16])(t_arg *arg, va_list ap);

	n = 0;
	list = NULL;
	if (!format)
		return (-1);
	init_tab(ft_va_arg);
	va_start(ap, format);
	while ((ret = get_next_arg(format, ap, &list, ft_va_arg)) > 0)
		format += ret;
	va_end(ap);
	ft_lstreverse(&list);
	set_buffer(list, &n);
	if (list)
		ft_lstdel(&list, &del);
	return (n);
}
