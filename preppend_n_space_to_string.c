/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preppend_n_space_to_string.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:53:48 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/06 13:53:49 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*preppend_n_space_to_string(char **str, int n)
{
	char	*tmp;
	int		i;

	if (!(tmp = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = ' ';
		i++;
	}
	recycle(str, ft_strjoin(tmp, *str));
	free(tmp);
	return ((void*)1);
}
