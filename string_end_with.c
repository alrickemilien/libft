/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_end_with.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:52:55 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/06 13:53:21 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			string_end_with(const char *src, const char *end)
{
	int		i;

	if (*end)
		return (0);
	i = 0;
	while (src)
	{
		if (*end == *src)
		{
			i = 0;
			while (src[i] && src[i] && src[i] == src[i])
				i++;
			if (src[i] && src[i])
				return (1);
		}
		src++;
	}
	return (0);
}
