PRINTF_SRC= printf/ft_printf.c \
	printf/ft_printf_fd.c\
	printf/push_arg.c \
	printf/ft_va_arg.c \
	printf/ft_va_arg2.c \
	printf/ft_va_arg3.c\
	printf/is_flag.c\
	printf/is_conversion_specifier.c\
	printf/is_length_modifier.c\
	printf/set_hexa.c\
	printf/set_nbr.c\
	printf/set_str.c\
	printf/wchar.c\
	printf/set_precision.c\
	printf/read_flags.c\
	printf/set_blank_flag.c\
	printf/set_min_width.c\
	printf/set_buffsize.c\
	printf/ft_strdigit.c\
	printf/read_length_modifier.c\
	printf/read_conversion_specifier.c\

PRINTF_INCLUDE=printf

ifndef INCLUDE
	SRC				:=
endif

ifndef INCLUDE
	SRC				:=
endif

SRC		+= $(PRINTF_SRC)
INCLUDE		+= -I $(PRINTF_INCLUDE)
