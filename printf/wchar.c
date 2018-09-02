/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 16:01:23 by aemilien          #+#    #+#             */
/*   Updated: 2017/05/16 09:38:37 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				whatsize(wchar_t c)
{
	int			len;

	if (c <= 0x7F)
		len = 1;
	else if (c <= 0x7FF)
		len = 2;
	else if (c <= 0xFFFF)
		len = 3;
	else if (c <= 0x10FFFF)
		len = 4;
	else
		len = 0;
	return (len);
}

static void		set_utf8_value(char *s, wchar_t c, int l)
{
	if (l == 1)
		s[0] = c;
	else if (l == 2)
	{
		s[0] = 192 | (c >> 6);
		s[1] = 128 | (c & 63);
	}
	else if (l == 3)
	{
		s[0] = 224 | (c >> 12);
		s[1] = 128 | ((c >> 6) & 63);
		s[2] = 128 | (c & 63);
	}
	else
	{
		s[0] = 240 | (c >> 18);
		s[1] = 128 | ((c >> 12) & 63);
		s[2] = 128 | ((c >> 6) & 63);
		s[3] = 128 | (c & 63);
	}
}

char			*wchar_to_str(wchar_t c)
{
	int			l;
	char		*s;

	l = whatsize(c);
	if (!l)
		return (ft_strdup(""));
	if (!(s = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	s[l] = 0;
	set_utf8_value(s, c, l);
	return (s);
}

char			*wstr_to_str(wchar_t *s)
{
	char		*res;
	char		*t;

	res = NULL;
	t = NULL;
	while (*s)
	{
		if (!res)
			res = wchar_to_str(*s);
		else
		{
			t = wchar_to_str(*s);
			recycle(&res, ft_strjoin(res, t));
			if (t)
				free(t);
		}
		s++;
	}
	return (res);
}
