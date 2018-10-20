/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:46:48 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/20 13:48:49 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbuffer.h"

/*
** Allocate a buffer
*/

t_buffer		*create_buffer(void)
{
	t_buffer	*ret;

	ret = (t_buffer*)malloc(sizeof(t_buffer));
	if (ret == NULL)
		return (NULL);
	ret->buf = (char*)malloc(sizeof(char) * MAX_BUFF_SIZE);
	if (!ret->buf)
	{
		free(ret);
		return (NULL);
	}
	ret->size = 0;
	return (ret);
}
