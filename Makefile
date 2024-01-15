NAME        			:= cub3D
OS_NAME     			:= $(shell uname -s)

ifeq ($(OS_NAME), Linux)
    FSANITIZE           := -fsanitize=address -fsanitize=leak
    FRAMEWORK           :=
    LINUX_LIBS          := -lXext -lX11
    LINUX_INCLUDES      := -I/usr/include
    MLX_DIR             := ./minilibx/minilibx-linux
    OS_FLAG             := -D LINUX
else
    FSANITIZE           := -fsanitize=address
    FRAMEWORK           := -framework OpenGL -framework AppKit
    LINUX_LIBS          :=
    LINUX_INCLUDES      :=
    MLX_DIR             := ./minilibx/mlx
    OS_FLAG             := -D OSX
endif

SANITIZE            	:= 0

ifeq ($(SANITIZE), 1)
    CFLAGS         		+= -fsanitize=address -g3
endif

ifdef debug
    FSANITIZE        	= -g
endif

CC                  	:= cc
CFLAGS              	:= -Wall -Werror -Wextra $(FSANITIZE) $(OS_FLAG)

OBJ_DIR             	:= ./objects/
INCLUDE_DIR         	:= ./include/
MAIN_SRCS				:= ./src/
BONUS_SRCS				:= ./src/bonus/

MLX			           	:= $(MLX_DIR)/libmlx.a
GNL_DIR             	:= ./src/get_next_line
GNL                 	:= $(GNL_DIR)/libgnl.a
LIBFT_DIR           	:= ./src/Libft
LIBFT               	:= $(LIBFT_DIR)/libft.a

LIBRARIES           	:= -lmlx -lm -L. -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl \
								$(FRAMEWORK) $(LINUX_LIBS) -L$(MLX_DIR)
INCLUDES            	:= -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(INCLUDE_DIR) -I$(MLX_DIR) \
								$(LINUX_INCLUDES)

HEADER					:= cub3d.h\
							enums.h\
							struct.h

HEADER_BONUS			:= cub3d_bonus.h\
							enums.h\
							struct.h
							
HEADER_FILES			:= $(addprefix $(INCLUDE_DIR), $(HEADER))
HEADER_BONUS_FILES		:= $(addprefix $(INCLUDE_DIR), $(HEADER_BONUS))

SRC_FILES				:= main.c\
							check_map.c\
							create_vectorpoint.c\
							draw_3d.c\
							draw_line.c\
							draw_map.c\
							get_textures.c\
							init_player.c\
							init.c\
							parsing.c\
							pixel_color.c\
							raycaster_angles.c\
							raycaster_castrays.c\
							raycaster.c\
							mlx_draw.c\
							mlx_init.c\
							hooks.c\
							utils.c\
							movement_y.c\
							movement_x.c\
							texture.c


BONUS_FILES         	:= main_bonus.c\


OBJ_LIST                := $(patsubst %.c,%.o,$(SRC_FILES))
OBJS                    := $(addprefix $(OBJ_DIR),$(OBJ_LIST))


BONUS_OBJ_LIST			:= $(patsubst %.c,%.o,$(BONUS_FILES))
BONUS_OBJS              := $(addprefix $(OBJ_DIR), $(BONUS_OBJ_LIST))

### RULES ###
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(MAIN_SRCS)%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(OBJ_DIR) $(MAIN_OBJ) $(OBJS) $(HEADER_FILES)
	@echo "Making libft..."
	@make -C $(LIBFT_DIR)
	@echo "Libft done."
	@make -C $(GNL_DIR)
	@echo "get_next_line done"
	@make -C ${MLX_DIR}
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) $(INCLUDES) $(LIBRARIES) -o $(NAME)
	@echo "Done."

bonus: $(NAME)_bonus
$(OBJ_DIR)%.o: $(BONUS_SRCS)%.c $(HEADER_BONUS_FILES)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME)_bonus: $(OBJ_DIR) $(BONUS_OBJS) $(HEADER_BONUS_FILES)
	@echo "Compiling bonus..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(INCLUDES) $(LIBRARIES) -o $(NAME)
	@echo "Done."

sanitize: fclean
	@echo "Compiling with sanitize..."
	@make SANITIZE=1

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	@make clean -C ${MLX_DIR}
	@echo "Cleaned."

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: sanitize all clean fclean re
