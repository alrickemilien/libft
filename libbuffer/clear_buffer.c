/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:45:54 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/20 13:46:26 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbuffer.h"

/*
** Allocate a buffer
*/

void	clear_buffer(t_buffer *buffer)
{
	flush_buffer(buffer);
	free(buffer->buf);
	buffer->buf = NULL;
	buffer->size = 0;
}
