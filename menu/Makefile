# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 19:25:17 by rnovodra          #+#    #+#              #
#    Updated: 2018/07/27 19:25:19 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	filler_menu

SRC				=	main.c \
					ft_menu_error.c \
					ft_choose.c \
					ft_main_window.c \
					ft_start_game.c \
				
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR			=	./src/
OBJ_DIR			=	./obj/
INC_DIR			=	./inc/
LIB_DIR			=	./../lib/

LIBFT_DIR		=	$(LIB_DIR)libft/

LIBFT			=	$(LIBFT_DIR)libft.a

PRINTF_DIR		=	$(LIB_DIR)ft_printf/

LIBPRINTF		=	$(PRINTF_DIR)libftprintf.a

HEAD_PRINTF		=	$(PRINTF_DIR)$(INC_DIR)ft_printf.h
HEAD_LIBFT		=	$(LIBFT_DIR)$(INC_DIR)libft.h
HEAD_VISUAL		=	$(INC_DIR)filler_interface.h

HEAD_FLAGS		=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)

LIBS_FLAGS		=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf

CC_FLAGS		=	-Wall -Werror -Wextra -std=c11

GTK_FLAG_OBJ	=	`pkg-config --cflags gtk+-3.0`

GTK_FLAG_BIN	=	`pkg-config --libs gtk+-3.0`

CC				=	gcc

BG				=	"\033[32;1m"
BR				=	"\033[31;1m"
EOC				=	"\033[0m"

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBPRINTF)
	@make -C $(LIBFT_DIR)

$(LIBPRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(GTK_FLAG_BIN) $(LIBS_FLAGS)
	@echo ${BG}"menu is ready"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_FILLER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) $(GTK_FLAG_OBJ)
	@echo ${BG}"[✓] $<"

clean:
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] clean"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 
