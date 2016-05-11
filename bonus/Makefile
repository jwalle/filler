# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/07 17:35:39 by jwalle            #+#    #+#              #
#    Updated: 2016/04/24 17:47:24 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= bonus

SRC 		=	bonus.c \
				get_next_line.c \

OBJ			= $(SRC:.c=.o)

INC			=	-I../inc -I../libft/includes -I./glfw/include
LINK		=	-L../libft -lft -L./glfw/src/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework GLUT -framework Carbon
SRCDIR		= ./srcs/
ODIR		= ./objs/

CFLAGS		=	-Wall -Wextra -Werror
FLAGS		=	$(CFLAGS)

CC			=	clang
RM			=	/bin/rm -f

OBJ			=	$(SRC:.c=.o)
SRCS		= 	$(addprefix $(SRCDIR), $(SRC))
OBJS		= 	$(addprefix $(ODIR), $(OBJ))

all			:	$(NAME)

$(NAME)		:
	cmake -B./glfw -H./glfw
	make -C ./glfw
	$(CC) $(SRCS) $(LINK) $(INC) -o $(NAME)	

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
