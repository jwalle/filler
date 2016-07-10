/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_display.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 17:50:39 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/06 17:50:48 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_DISPLAY_H
#define FILLER_DISPLAY_H

#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include <stdio.h> //A RETIRER
#include "../libft/libft.h"
#include "get_next_line.h"

#define FORMAT "*.OoxX"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

#define WIDTH 1200
#define HEIGHT 1000

#define RED_PLOP 1.0f, 0.0f, 0.0f

typedef struct	s_env
{
	int			player;
	char		**map;
	char		**piece;
	int			*piece_size;
	int			*map_size;
}				t_env;

void disp_square_red(int x, int y);
void disp_square_white(int x, int y);
void disp_square_green(int x, int y, float start_y);
void disp_square_blue(int x, int y);
void get_play(float y, char **str, t_env *e);
char **get_map(t_env *e, char *line);
char **get_piece(char *line, t_env *e);
int	*get_size_bonus(char *line, t_env *e);

#endif