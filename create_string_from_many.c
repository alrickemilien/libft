/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_string_from_many.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:55:01 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/06 13:55:27 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*create_string_from_many(const char **many_strings, int size)
{
	int		i;
	int		full_length;
	char	*ret;

	i = 0;
	full_length = 0;
	while (i < size)
	{
		full_length += ft_strlen(many_strings[i]);
		i++;
	}
	if ((ret = malloc(sizeof(char) * (full_length + 1))) == NULL)
		return (NULL);
	ft_bzero(ret, full_length + 1);
	i = 0;
	while (i < size)
	{
		ft_memcpy(ret + ft_strlen(ret),
				many_strings[i],
				ft_strlen(many_strings[i]));
		i++;
	}
	return (ret);
}
