NAME        			:= cub3D
OS_NAME     			:= $(shell uname -s)

ifeq ($(OS_NAME), Linux)
    FSANITIZE           := -fsanitize=address -fsanitize=leak
    FRAMEWORK           :=
    LINUX_LIBS          := -lXext -lX11
    LINUX_INCLUDES      := -I/usr/include
    MLX_DIR             := ../minilibx/minilibx-linux
    OS_FLAG             := -D LINUX
else
    FSANITIZE           := -fsanitize=address
    FRAMEWORK           := -framework OpenGL -framework AppKit
    LINUX_LIBS          :=
    LINUX_INCLUDES      :=
    MLX_DIR             := ../minilibx/mlx
    OS_FLAG             := -D OSX
endif

SANITIZE            	:= 0

ifeq ($(SANITIZE), 1)
    CFLAGS         		+= -fsanitize=address -g3
endif

ifdef debug
    FSANITIZE        	= -g
endif

CC                  	:= gcc
CFLAGS              	:= -Wall -Werror -Wextra $(FSANITIZE) $(OS_FLAG)

OBJ_DIR             	:= ./objects/
INCLUDE_DIR         	:= ../include/
TEST_SRCS_DIR			:= ./
MAIN_SRCS				:= ../src/

MLX			           	:= $(MLX_DIR)/libmlx.a
GNL_DIR             	:= ../src/get_next_line
GNL                 	:= $(GNL_DIR)/libgnl.a
LIBFT_DIR           	:= ../src/Libft
LIBFT               	:= $(LIBFT_DIR)/libft.a


LIBRARIES           	:= -lmlx -lm -L. -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl \
								$(FRAMEWORK) $(LINUX_LIBS) -L$(MLX_DIR)
INCLUDES            	:= -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(INCLUDE_DIR) -I$(MLX_DIR) \
								$(LINUX_INCLUDES)

HEADER					:= cub3d.h\
							enums.h\
							struct.h
							
HEADER_FILES			:= $(addprefix $(INCLUDE_DIR), $(HEADER))

FILES               	:= main.c

SRC_FILES				:= create_vectorpoint.c\
							draw_3d.c\
							draw_line.c\
							draw_map.c\
							init_player.c\
							pixel_color.c\
							raycaster_angles.c\
							raycaster_castrays.c\
							raycaster.c\
							mlx_draw.c\
							mlx_init.c\
							hooks.c\
							utils.c\
							movement_y.c\
							movement_x.c

OBJ_LIST                := $(patsubst %.c,%.o,$(FILES))
OBJS                    := $(addprefix $(OBJ_DIR),$(OBJ_LIST))

SRC_OBJ_LIST			:= $(patsubst %.c,%.o,$(SRC_FILES))
SRC_OBJS                := $(addprefix $(OBJ_DIR), $(SRC_OBJ_LIST))

### RULES ###
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(TEST_SRCS_DIR)%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(OBJ_DIR)%.o: $(MAIN_SRCS)/%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@


$(NAME): $(OBJ_DIR) $(SRC_OBJS) $(OBJS) $(HEADER_FILES)
	@echo "Making libft..."
	@make -C $(LIBFT_DIR)
	@echo "Libft done."
	@make -C $(GNL_DIR)
	@echo "get_next_line done"
	@make -C ${MLX_DIR}
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(SRC_OBJS) $(INCLUDES) $(LIBRARIES) -o $(NAME)
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
