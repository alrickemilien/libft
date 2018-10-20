/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:54:11 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/06 13:54:32 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sort by alphabetique and not by ASCII value
*/

int					ft_strcmp_alpha(char *s1, char *s2)
{
	int				i;
	int				n;

	n = ft_strlen(s1) + 1;
	if (!n)
		return (0);
	i = 0;
	while (i < n)
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
		i++;
	}
	return (0);
}
