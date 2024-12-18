# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 22:33:41 by gmarchal          #+#    #+#              #
#    Updated: 2024/01/22 17:59:48 by gmarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
    FSANITIZE           := #-fsanitize=address
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
CFLAGS              	:= -Wall -Werror -Wextra -O3 $(OS_FLAG) $(FSANITIZE) 

OBJ_DIR             	:= ./objects/
INCLUDE_DIR         	:= ./include/
MAIN_SRCS				:= ./src/

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
							
HEADER_FILES			:= $(addprefix $(INCLUDE_DIR), $(HEADER))

SRC_FILES				:= main.c\
							calc_mapdimensions.c\
							check_map.c\
							create_vectorpoint.c\
							draw_3d.c\
							draw_3d_utils.c\
							draw_map.c\
							free.c\
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
							movement_utils.c\
							movement_y.c\
							movement_x.c\
							texture.c\
							process_map.c\
							check_utils.c\
							check_colors.c

OBJ_LIST                := $(patsubst %.c,%.o,$(SRC_FILES))
OBJS                    := $(addprefix $(OBJ_DIR),$(OBJ_LIST))

### RULES ###
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(MAIN_SRCS)%.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER_FILES)
	@echo "Making libft..."
	@make -C $(LIBFT_DIR)
	@echo "Libft done."
	@make -C $(GNL_DIR)
	@echo "get_next_line done"
	@make -C ${MLX_DIR}
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBRARIES) -o $(NAME)
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
