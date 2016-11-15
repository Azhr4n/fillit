# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:00:02 by achauvea          #+#    #+#              #
#    Updated: 2016/11/15 11:40:46 by achauvea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS_PATH	= srcs/

SRCS_NAME	= memset bzero memcpy memccpy memmove memchr memcmp strlen strdup  \
			  strcpy strlcpy strncpy strcat strncat strlcat strchr strrchr     \
			  strstr strnstr strcmp strncmp atoi isalpha isdigit isalnum       \
			  isascii isprint toupper tolower memalloc memdel strnew strdel    \
			  strclr striter striteri strmap strmapi strequ strnequ strsub     \
			  strjoin strtrim strsplit itoa putchar putstr putendl putnbr      \
			  putchar_fd putstr_fd putendl_fd putnbr_fd lstnew lstdelone       \
			  lstdel lstadd lstiter lstmap isblank iscntrl isgraph isspace     \
			  isupper islower isxdigit str_is_alpha str_is_lowercase           \
			  str_is_numeric str_is_printable str_is_uppercase strcapitalize   \
			  strlowcase strupcase wordcutlen wordscutlen lstfold sqrtf        \
			  get_next_line                                                    \

HEADER		= includes/

CC			= gcc

CFLAGS		= -I $(HEADER) -Wall -Wextra -Werror

OBJ_PATH	= obj/

OBJ_NAME	= $(addprefix $(OBJ_PATH)ft_,$(SRCS_NAME))

OBJ			= $(addsuffix .o,$(OBJ_NAME))

$(NAME): $(OBJ_PATH) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o : $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

.PHONY : all clean fclean re update

all: $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

update:
	git fetch --all
	git reset --hard origin/master
