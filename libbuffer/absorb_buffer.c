#include "libbuffer.h"

/*
** Append buffer than free the string and sets it to NULL
*/

void absorb_buffer(t_buffer* buffer, char** str)
{
	append_buffer(buffer, *str);
	free(*str);
	*str = NULL;
}