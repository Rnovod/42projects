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

NAME = vizualizator

MAIN = $(addprefix src/, sdl_manage.c main.c init_str.c events.c draw_map.c \
		draw_interface.c)

OBJ = $(MAIN:.c=.o)

FLAGS = -Wall -Wextra -Werror

SDL_LIB			=	-L ~/.brew/lib -lSDL2 -lSDL2_ttf -lSDL2_mixer
SDL_HEADER		=	-I ~/.brew/include/ -D_THREAD_SAFE -I ~/.brew/include/SDL2/

HEADER = ./inc/vizualization.h

all : $(NAME)

$(NAME) : $(MAIN) $(HEADER)
	make -C ../libft/
	gcc $(FLAGS) $(SDL_LIB) $(SDL_HEADER) -L../libft/ -lft -I ./inc -I ../inc $(MAIN) -o $(NAME)

%.o : %.c
	gcc -c -o $@ $< $(FLAGS) $(SDL_FLAGS) -I./inc

clean :
	@rm -rf $(OBJ)
	@rm -rf $(main)
	make -C ../libft/ clean
fclean : clean
	rm -rf $(NAME) 
	make -C ../libft/ fclean 

re : fclean all
