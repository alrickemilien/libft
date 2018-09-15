#include "libbuffer.h"

/*
** Allocate a buffer
*/

void append_buffer(t_buffer* buffer, char* str)
{
	int string_length;

	string_length = (int)ft_strlen(str);
	if (buffer->size + string_length > MAX_BUFF_SIZE)
	{
		write(1, buffer->buf, buffer->size);
		buffer->size = string_length;
		ft_bzero(buffer->buf, sizeof(char) * MAX_BUFF_SIZE);
		ft_memcpy(buffer->buf, str, string_length);
		return ;
	}

	ft_memcpy(buffer->buf, str, string_length);
	buffer->size += string_length;
}