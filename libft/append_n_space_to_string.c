/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_n_space_to_string.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:55:45 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/06 13:55:58 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*append_n_space_to_string(char **str, int n)
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
	recycle(str, ft_strjoin(*str, tmp));
	free(tmp);
	return ((void*)1);
}
