#include "libbuffer.h"

/*
** Allocate a buffer
*/

t_buffer	*create_buffer(void)
{
	t_buffer *ret;

	ret = (t_buffer*)malloc(sizeof(t_buffer));

	if (ret == NULL)
		return (NULL);
	
	ret->buf = (char*)malloc(sizeof(char) * MAX_BUFF_SIZE);

	if (!ret->buf) {
		free(ret);
		return (NULL);
	}

	ret->size = 0;

	return (ret);
}