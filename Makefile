NAME		=	cub3D

FILES		=	main.c\

SRC		=	$(addprefix src/, $(FILES))

OBJS		=	$(SRC:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SANITIZE	=	0

ifeq ($(SANITIZE), 1)
	CFLAGS	+= -fsanitize=address -g3
endif

### RULES ###

$(NAME):		$(OBJS)
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) $(DIRS) $(READL) -o $(NAME)
				@echo "Done."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				
all:			$(NAME)

sanitize:		fclean
				@echo "Compiling with sanitize..."
				@make SANITIZE=1

clean:
				@echo "Cleaning..."
				@rm -f $(OBJS)
				@echo "Cleaned."

fclean:			clean
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize all clean fclean re
