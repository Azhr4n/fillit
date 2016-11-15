# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:00:02 by achauvea          #+#    #+#              #
#    Updated: 2016/11/15 16:03:30 by achauvea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

SRCS_PATH	= srcs/

SRCS_NAME	= core struct_core get_piece_value resolve_result put_piece \

HEADER		= includes/

CC			= gcc

CFLAGS		= -I $(HEADER) -I libft/$(HEADER) -Wall -Wextra -Werror

OBJ_PATH	= obj/

OBJ_NAME	= $(addprefix $(OBJ_PATH),$(SRCS_NAME))

OBJ			= $(addsuffix .o,$(OBJ_NAME))

$(NAME): $(OBJ_PATH) $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(OBJ_PATH)%.o : $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

.PHONY : all clean fclean re update

all: $(NAME)

clean:
	make clean -C libft/
	rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

update:
	git fetch --all
	git reset --hard origin/master
