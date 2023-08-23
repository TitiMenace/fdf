# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 05:15:52 by tschecro          #+#    #+#              #
#    Updated: 2023/08/22 17:29:48 by tschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	main.c fdf_utils.c get_next_line.c get_next_line_utils.c \
					check_map.c parsing.c draw_map.c draw_line.c \
					get_color.c mlx.c hooks.c isometric.c rotates.c color.c\
					initialization.c cinematic_hooks.c parsing_utils.c\
					mlx_utils.c colors_hooks.c draw_helper.c \
					draw_map_utils.c rotates_utils.c draw_line_utils.c \
					truncate_line.c check_collide_utils.c

SRC_DIR 		= src

SRC		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

LIBS_FOLDER		=  lib

INCLUDES_DIR	= includes

INCLUDES_FILES	= 	includes.h\
					fdf.h\
					struct.h

INCLUDES		= $(addprefix $(INCLUDES_DIR)/,$(INCLUDES_FILES))

OBJ_DIR = .build

OBJ		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC) )

MLX_DIR = minilibx-linux
MLX = ./$(LIBS_FOLDER)/$(MLX_DIR)/libmlx_Linux.a

LIBS = $(MLX)

NAME	=	fdf	

CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS)
			$(CC) $(OBJ) $(LIBS) -lm -lXext -lX11 -o $(NAME)
			@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_DIR)/%.o 		:	$(SRC_DIR)/%.c $(INCLUDES)
						@printf "\033[0;33m Generating fdf object... %-38.38s \r" $@
						@mkdir -p $(OBJ_DIR)
						@$(CC) -Wall -Wextra -Werror -g3 -O3 -Ofast -c -I $(INCLUDES_DIR) $< -o $@

clean	:
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJ_BONUS_DIR)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

bonus	:	all

$(LIBS)	:				
			make -C $(LIBS_FOLDER)/$(MLX_DIR)

cleanlib :
			make fclean -C $(LIBS_FOLDER)/$(MLX_DIR)

.PHONY	:	all clean fclean re cleanlib
