# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:55:10 by fkaratay          #+#    #+#              #
#    Updated: 2022/02/25 17:57:18 by fkaratay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= $(wildcard src/*.c) $(wildcard utils/*.c) ./mandatory/render_map.c ./so_long.c

SRCS_BONUS	= $(wildcard src/*.c) $(wildcard utils/*.c) ./bonus/render_map_bonus.c ./so_long.c

OBJS		= $(SRCS:%.c=%.o)

OBJS_BONUS	= $(SRCS_BONUS:%.c=%.o)

$(NAME):	$(OBJS)
			make -C ./mlx
			mv ./mlx/libmlx.a ./libmlx.a
			$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a -o $(NAME)


bonus:		$(OBJS_BONUS)
			make -C ./mlx
			mv ./mlx/libmlx.a ./libmlx.a
			$(CC) $(CFLAGS) $(SRCS_BONUS) -framework OpenGL -framework AppKit libmlx.a -o $(NAME)

all: 		$(NAME)

clean:
			make -C ./mlx clean
			rm -rf */*.o libmlx.a so_long.o

fclean: 	clean
			rm -rf so_long

re: 		fclean all

.PHONY: 	all clean fclean re bonus
