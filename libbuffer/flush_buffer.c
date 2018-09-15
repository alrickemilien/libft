#include "libbuffer.h"

/*
** Allocate a buffer
*/

void flush_buffer(t_buffer* buffer)
{
	write(1, buffer->buf, buffer->size);
	buffer->size = 0;
	ft_bzero(buffer->buf, sizeof(char) * MAX_BUFF_SIZE);
}