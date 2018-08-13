# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/28 17:17:15 by rnovodra          #+#    #+#              #
#    Updated: 2018/04/28 17:17:19 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	rnovodra.filler

VISUAL		=	$(VISUAL_DIR)visual

INTERFACE	=	$(INTER_DIR)filler_menu

SRC			=	main.c \
				ft_map.c \
				ft_piece.c \
				ft_get_player_nbr.c \
				ft_filler.c \
				ft_error.c \
				ft_eval_answer.c \
				ft_filler_exit.c \

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/
LIB_DIR		=	./lib/

VISUAL_DIR	=	./visualization/

INTER_DIR	=	./interface/

LIBFT_DIR	=	$(LIB_DIR)libft/

LIBFT		=	$(LIBFT_DIR)libft.a

PRINTF_DIR	=	$(LIB_DIR)ft_printf/

LIBPRINTF	=	$(PRINTF_DIR)libftprintf.a

HEAD_PRINTF	=	$(PRINTF_DIR)$(INC_DIR)ft_printf.h
HEAD_LIBFT	=	$(LIBFT_DIR)$(INC_DIR)libft.h

HEAD_FILLER	=	$(INC_DIR)filler.h

HEAD_FLAGS	=	-I $(INC_DIR) -I $(PRINTF_DIR)$(INC_DIR) -I $(LIBFT_DIR)$(INC_DIR)

LIBS_FLAGS	=	-L $(PRINTF_DIR) -lft -L $(LIBFT_DIR) -lftprintf

CC_FLAGS	=	-Wall -Werror -Wextra -std=c11

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"
EOC			=	"\033[0m"

all: $(LIBFT) $(INTERFACE) $(VISUAL) $(NAME)

$(INTERFACE):
	@make -C $(INTER_DIR)

$(VISUAL):
	@make -C $(VISUAL_DIR)

$(LIBFT): $(LIBPRINTF)
	@make -C $(LIBFT_DIR)

$(LIBPRINTF):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LIBS_FLAGS)
	@echo ${BG}"filler is ready to fight"${EOC}

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEAD_FILLER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS) 
	@echo ${BG}"[✓] $<"

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(VISUAL_DIR)
	@make clean -C $(INTER_DIR)
	@rm -rf $(OBJ)
	@echo ${BR}"[✗] clean"

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(VISUAL_DIR)
	@make fclean -C $(INTER_DIR)
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo ${BR}"[✗] $(NAME)"

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all fclean clean re 
