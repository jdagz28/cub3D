NAME		=	cub3D

FILES		=	main.c\
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				parsing.c\
				init.c\
				texture.c\
				utils.c\

SRC		=	$(addprefix src/, $(FILES))

OBJS		=	$(SRC:.c=.o)

OBJS_MLX	=	$(MLX_DIR:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

ifeq ($(SANITIZE), 1)
	CFLAGS	+= -fsanitize=address -g3
endif

### Get_next_line
GNL_DIR		= src/get_next_line

### Libft
LIBFT_DIR	=	src/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

### Minilibx
MLX_DIR		= minilibx/mlx
MLX_PATH 	= $(MLX_DIR)/libmlx.a
MLX			= -framework OpenGL -framework AppKit ${MLX_PATH}

SANITIZE	=	0

### RULES ###

$(NAME):		$(OBJS)
				@echo "Making libft..."
				@make -C $(LIBFT_DIR)
				@echo "Libft done."
				@make -C ${MLX_DIR}
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) $(DIRS) $(READL) $(GNL) $(LIBFT) $(MLX) -o $(NAME)
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
				@make clean -C $(LIBFT_DIR)
				@make clean -C ${MLX_DIR}
				@echo "Cleaned."

fclean:			clean
				@make fclean -C $(LIBFT_DIR)
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize all clean fclean re
