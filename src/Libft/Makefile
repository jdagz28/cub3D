# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 15:22:24 by gmarchal          #+#    #+#              #
#    Updated: 2024/01/03 15:04:08 by jdagoy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_memset ft_memcpy ft_memmove ft_memchr ft_memcmp \
	    ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_bzero\
		ft_tolower ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strlen \
		ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strtrim \
		ft_split ft_itoa ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		ft_putnbr_fd ft_striteri ft_lstnew_bonus ft_lstsize_bonus ft_lstmap_bonus ft_lstlast_bonus \
		ft_lstiter_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstadd_front_bonus ft_lstadd_back_bonus

SRCS = $(addsuffix .c, $(FILES))

OBJ_DIR = ./objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRCS))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

CC = gcc

RM = rm -f

all: $(NAME)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJ_DIR) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
