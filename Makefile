# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aemilien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 11:45:00 by aemilien          #+#    #+#              #
#    Updated: 2017/05/14 15:03:14 by aemilien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include printf.mk
include libft.mk
include libbuffer.mk

CCFLAGS= -Wall -Wextra -Werror

OBJ=$(SRC:.c=.o)

NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@gcc -o $@ -c $< $(INCLUDE) $(CCFLAGS)

clean:
	@rm -rf $(OBJ)

.PHONY: clean fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
