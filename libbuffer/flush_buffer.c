/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:47:34 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/20 13:48:39 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbuffer.h"

/*
** Allocate a buffer
*/

void	flush_buffer(t_buffer *buffer)
{
	write(1, buffer->buf, buffer->size);
	buffer->size = 0;
	ft_bzero(buffer->buf, sizeof(char) * MAX_BUFF_SIZE);
}
