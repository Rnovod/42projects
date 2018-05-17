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

NAME		=	libftprintf.a

SRC			=	ft_printf.c \
				ft_specification.c \
				ft_print_buff.c \
				ft_conversion.c \
				ft_set_default.c \
				ft_star.c \
				ft_get_arg.c \
				ft_d.c \
				ft_c.c \
				ft_u.c \
				ft_s.c \
				ft_f.c \
				ft_printf_itoa.c \
				ft_printf_putchar.c \
				ft_printf_putstr.c \
				ft_putstr_unicode.c \
				ft_itoa_float.c

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
INC_DIR		=	./inc/

HEADER		=	$(INC_DIR)ft_printf.h

HEAD_FLAGS	=	-I $(INC_DIR)

CC_FLAGS	=	-Wall -Werror -Wextra

CC			=	gcc

BG			=	"\033[32;1m"
BR			=	"\033[31;1m"

all: $(NAME)

main : main.c
	@$(CC) main.c libftprintf.a
	@echo "compile with main"
	@./a.out

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo ${BG}"ft_printf is ready"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEAD_FLAGS)
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
