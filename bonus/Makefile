# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/07 17:35:39 by jwalle            #+#    #+#              #
#    Updated: 2016/07/06 18:41:27 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= bonus

SRC 		=	bonus.c \
				get_next_line.c \
				get_bonus.c \
				square.c \

OBJ			= $(SRC:.c=.o)

INC			=	-I../inc -I../libft/includes -I./glfw/include -I./includes
LINK		=	-L../libft -lft -L./glfw/src/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework GLUT -framework Carbon
LINK_LINUX	=	-L../libft -lft -L./glfw/src/ -lglfw3 -lm -ldl -lGL -lglut -lX11 -lXxf86vm -lXinerama -lXcursor -lXrandr -lpthread -lXi
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
	$(CC) $(FLAGS) srcs/map_gen.c -o map_gen -I./includes
	#cmake -B./glfw -H./glfw
	#make -C ./glfw
	$(CC) $(SRCS) $(LINK) $(INC) -o $(NAME)	

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)
	$(RM) map_gen

re			:	fclean all

linux		:	fclean
				clang $(SRCS) $(LINK_LINUX) $(INC) -o $(NAME)	


%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
