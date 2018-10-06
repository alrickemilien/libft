LIBBUFFER_SRC += libbuffer/absorb_buffer.c \
			libbuffer/clear_buffer.c \
			libbuffer/delete_buffer.c \
			libbuffer/append_buffer.c \
			libbuffer/create_buffer.c \
			libbuffer/flush_buffer.c

LIBBUFFER_INCLUDE=libbuffer

ifndef SRC
	SRC				:=
endif

ifndef INCLUDE
	INCLUDE				:=
endif

SRC		+= $(LIBBUFFER_SRC)
INCLUDE	+= -I $(LIBBUFFER_INCLUDE)
