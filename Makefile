NAME		=	cub3D

FILES		=	main.c\
				hooks.c\

SRC		=	$(addprefix src/, $(FILES))

OBJS		=	$(SRC:.c=.o)

OBJS_MLX	=	$(MLX_DIR:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

# Get_next_line
GNL_DIR		= src/get_next_line

# Minilibx
MLX_DIR		= mlx

MLX_PATH 	= $(MLX_DIR)/libmlx.a

MLX			= -framework OpenGL -framework AppKit ${MLX_PATH}

SANITIZE	=	0

ifeq ($(SANITIZE), 1)
	CFLAGS	+= -fsanitize=address -g3
endif

### RULES ###

$(NAME):		$(OBJS)
				@make -C ${MLX_DIR}
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) $(DIRS) $(READL) $(GNL) $(MLX) -o $(NAME)
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
				@make clean -C ${MLX_DIR}
				@echo "Cleaned."

fclean:			clean
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize all clean fclean re
