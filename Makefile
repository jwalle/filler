# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/07 17:35:39 by jwalle            #+#    #+#              #
#    Updated: 2016/04/19 17:17:10 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= filler

SRC 		=	filler.c \
				get_next_line.c \
				misc.c \
				check.c \
				get_all.c \

INC			=	-I./inc -I./libft/includes
LINK		=	-Llibft -lft
SRCDIR		= ./srcs/
ODIR		= ./objs/

CFLAGS		=	-Wall -Wextra -Werror
FLAGS		=	$(CFLAGS)

CC			=	clang
RM			=	/bin/rm -f

OBJ			=	$(SRC:.c=.o)
OBJS		= 	$(addprefix $(ODIR), $(OBJ))

all			:	$(NAME)

$(NAME)		:	$(OBJS)
	#make -C ./libft
	$(CC) -o $(NAME) $(LINK) $^ 

$(ODIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean		:
	#@make -C ./libft clean
	$(RM) $(OBJS)

fclean		:	clean
	#@make -C ./libft fclean
	$(RM) $(NAME)

re			:	fclean all

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
