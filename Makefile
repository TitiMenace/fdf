# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschecro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 05:15:52 by tschecro          #+#    #+#              #
#    Updated: 2023/06/21 06:01:46 by tschecro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES		=	main.c fdf_utils.c get_next_line.c get_next_line_utils.c \
					check_map.c parsing.c draw_map.c draw_line.c \
					get_color.c mlx.c hooks.c

SRC_FILES_BONUS	=	main.c fdf_utils.c get_next_line.c get_next_line_utils.c \
					check_map.c parsing.c draw_map.c draw_line.c \
					get_color.c mlx.c hooks.c isometric.c rotates.c color.c\

SRC_DIR_BONUS	= src_bonus

SRC_DIR 		= src

LIBS_FOLDER		=  lib

HEADER		= includes

SRC		=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))

SRC_BONUS	=	$(addprefix $(SRC_DIR_BONUS)/,$(SRC_FILES_BONUS) )

OBJ_DIR = .build

OBJ_BONUS_DIR = .bonus_build

OBJ		= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC) )

OBJ_BONUS = 	$(patsubst $(SRC_DIR_BONUS)/%.c, $(OBJ_BONUS_DIR)/%.o, $(SRC_BONUS) )

MLX_DIR = minilibx-linux
MLX = ./$(LIBS_FOLDER)/$(MLX_DIR)/libmlx_Linux.a

LIBS = $(MLX)

NAME	=	fdf	

BONUS_NAME	= fdf_bonus

CC		=	cc

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS)
			$(CC) $(OBJ) $(LIBS) -lm -lXext -lX11 -o $(NAME)
			@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_DIR)/%.o 		:	$(SRC_DIR)/%.c
						@printf "\033[0;33m Generating fdf object... %-38.38s \r" $@
						@mkdir -p $(OBJ_DIR)
						@$(CC) -Wall -Wextra -Werror -g3 -fsanitize=address -c -I $(HEADER) $< -o $@

clean	:
			rm -rf $(OBJ_DIR)
			rm -rf $(OBJ_BONUS_DIR)

fclean	:	clean
			rm -f $(NAME)
			rm -f $(BONUS_NAME)

re		:	fclean all

bonus	:	$(BONUS_NAME)

$(BONUS_NAME)	:	 	$(OBJ_BONUS) $(LIBS)
						$(CC) $(OBJ_BONUS) $(LIBS) -lm -lXext -lX11 -o $(BONUS_NAME)
						@echo "\033[1;32m\nDone!\033[0m"

$(OBJ_BONUS_DIR)/%.o 		:	$(SRC_DIR_BONUS)/%.c
						@printf "\033[0;33m Generating fdf object... %-38.38s \r" $@
						@mkdir -p $(OBJ_BONUS_DIR)
						@$(CC) -Wall -Wextra -Werror -O3 -g3 -c -I $(HEADER) $< -o $@

$(LIBS)	:				
			make -C $(LIBS_FOLDER)/$(MLX_DIR)

cleanlib :
			make fclean -C $(LIBS_FOLDER)/$(MLX_DIR)

.PHONY	:	all clean fclean re cleanlib
