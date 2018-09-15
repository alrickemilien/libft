LIBBUFFER_SRC += libbuffer/absorb_buffer.c \
			libbuffer/clear_buffer.c \
			libbuffer/delete_buffer.c \
			libbuffer/append_buffer.c \
			libbuffer/create_buffer.c \
			libbuffer/flush_buffer.c

LIBBUFFER_INCLUDE=libbuffer

ifndef INCLUDE
	SRC				:=
endif

ifndef INCLUDE
	SRC				:=
endif

SRC		+= $(LIBBUFFER_SRC)
INCLUDE	+= -I $(LIBBUFFER_INCLUDE)