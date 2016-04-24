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

INC			=	-I../inc -I../libft/includes
LINK		=	-L../libft -lft
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
	$(CC) -o $(NAME) $(LINK) $^ -lncurses 

$(ODIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
