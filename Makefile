# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 20:01:56 by pokpalae          #+#    #+#              #
#    Updated: 2024/05/31 12:29:39 by pokpalae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME				=	fractol


CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
LIBS      			=	-lXext -lX11 -lm
RM					=	rm -f


LIBFT				=	./libft/libft.a
MLX					=	./minilibx-linux/libmlx.a
INC					=	inc/ libft/ minilibx-linux/
SRC_DIR				=	src/
OBJ_DIR				=	obj/


SRC					=	main.c \
						initial_fract.c \
						render_chunk.c \
						events_hand.c \
						utils.c \
						help.c \
						color.c\
						draw_set.c

SRCS				=	$(addprefix $(SRC_DIR), $(SRC))


OBJ 				= 	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))



all: 					$(MLX) $(LIBFT) $(NAME)

$(NAME): 				$(OBJ) $(MLX) $(LIBFT)
						@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT) $(LIBS) -o $(NAME)

$(LIBFT):
						@make -sC ./libft

$(MLX):
						@make -sC ./minilibx-linux


$(OBJ_DIR)%.o:			$(SRC_DIR)%.c 
						@mkdir -p $(@D)
						@$(CC) $(CFLAGS) -c $< -o $@

clean:
						@$(RM) -r $(OBJ_DIR)
						@make clean -C ./minilibx-linux
						@make clean -C ./libft

fclean: 				clean
						@$(RM) $(NAME)
						@$(RM) $(MLX)
						@$(RM) $(LIBFT)

re: 					fclean all


.PHONY: 				all clean fclean re