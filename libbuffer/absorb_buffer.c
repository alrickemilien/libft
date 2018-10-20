/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absorb_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:44:45 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/20 13:45:18 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libbuffer.h"

/*
** Append buffer than free the string and sets it to NULL
*/

void	absorb_buffer(t_buffer *buffer, char **str)
{
	append_buffer(buffer, *str);
	free(*str);
	*str = NULL;
}
