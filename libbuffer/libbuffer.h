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
void			delete_buffer(t_buffer **);
void			append_buffer(t_buffer*, char*);
void			absorb_buffer(t_buffer*, char**);
void			flush_buffer(t_buffer*);
void			clear_buffer(t_buffer*);

#endif