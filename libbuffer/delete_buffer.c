#include "libbuffer.h"

/*
** Allocate a buffer
*/

void delete_buffer(t_buffer **buffer)
{
	if (*buffer && (*buffer)->buf)
		free((*buffer)->buf);
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
}