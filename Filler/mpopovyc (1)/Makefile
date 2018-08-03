# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 17:00:59 by mpopovyc          #+#    #+#              #
#    Updated: 2018/07/04 13:05:16 by mpopovyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all fclean clean re 

NAME = mpopovyc.filler

MAIN = $(addprefix src/, main.c fill_data.c choose_place.c init_str.c)

OBJ = $(MAIN:.c=.o)

FLAGS = -Wall -Wextra -Werror

SDL_LIB			=	-L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_mixer
SDL_HEADER		=	-I ~/.brew/include/ -D_THREAD_SAFE

HEADER = ./inc/filler.h

all : $(NAME)

$(NAME) : $(MAIN) $(HEADER)
	make -C libft/
	gcc $(FLAGS) -Llibft/ -lft -I ./inc $(MAIN) -o $(NAME) $(SDL_LIB) $(SDL_HEADER)

%.o : %.c
	gcc -c -o $@ $< $(FLAGS) -I./inc

clean :
	@rm -rf $(OBJ)
	@rm -rf $(main)
	make -C libft/ clean
fclean : clean
	rm -rf $(NAME) 
	make -C libft/ fclean 

re : fclean all
