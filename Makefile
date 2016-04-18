# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/07 17:35:39 by jwalle            #+#    #+#              #
#    Updated: 2016/04/18 16:58:40 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= filler

SRC 		=	filler.c \

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
	@make -C ./libft
	$(CC) -o $(NAME) $(LINK) $^ 

$(ODIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean		:
	@make -C ./libft clean
	@$(RM) $(OBJ)

fclean		:	clean
	@make -C ./libft fclean
	@$(RM) $(NAME)

re			:	fclean all

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
