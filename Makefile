# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/07 17:35:39 by jwalle            #+#    #+#              #
#    Updated: 2016/07/06 17:27:03 by jwalle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= filler

SRC 		=	filler.c \
				get_next_line.c \
				misc.c \
				check.c \
				get_all.c \

INC			=	-I./inc -I./libft
LINK		=	-L./libft -lft
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
	make -C ./libft
	$(CC) $(FLAGS) -o $(NAME) $^ $(LINK) 

$(ODIR)%.o : $(SRCDIR)%.c
	$(CC) $(FLAGS) -c $^ $(INC) -o $@

clean		:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean		:	clean
	make -C ./libft fclean
	make -C ./bonus fclean
	$(RM) $(NAME)

bonus		: $(NAME)
	make -C ./bonus

test		:
	./bonus/map_gen > maps/rand.map | ./ex_filler/filler_vm -p1 ./filler -p2 ./ex_filler/grati.filler -v -f maps/rand.map

test_bonus :
	./bonus/map_gen > maps/rand.map | ./ex_filler/filler_vm -p1 ./filler -p2 ./ex_filler/grati.filler -v -f maps/rand.map | ./bonus/bonus


re			:	fclean all

%.o			:	%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY : test_bonus bonus all test
