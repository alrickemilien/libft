/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:46:34 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/20 13:46:41 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbuffer.h"

/*
** Allocate a buffer
*/

void	delete_buffer(t_buffer **buffer)
{
	if (*buffer && (*buffer)->buf)
		free((*buffer)->buf);
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
}
