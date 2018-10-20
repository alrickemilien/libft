/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbuffer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemilien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:49:37 by aemilien          #+#    #+#             */
/*   Updated: 2018/10/20 13:49:45 by aemilien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBUFFER_H

# define LIBBUFFER_H

# include "libft.h"

# define MAX_BUFF_SIZE 514

/*
** Use this structure to create a char * buffer
** and always keep size info on it
*/

typedef struct	s_buffer {
	char		*buf;
	int			size;
}				t_buffer;

t_buffer		*create_buffer(void);
void			delete_buffer(t_buffer **buffer);
void			append_buffer(t_buffer *buffer, char *str);
void			absorb_buffer(t_buffer *buffer, char **str);
void			flush_buffer(t_buffer *buffer);
void			clear_buffer(t_buffer *buffer);

#endif
