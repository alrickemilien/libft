#include "libbuffer.h"

/*
** Allocate a buffer
*/

void clear_buffer(t_buffer* buffer)
{
	flush_buffer(buffer);
	free(buffer->buf);
	buffer->buf = NULL;
	buffer->size = 0;
}