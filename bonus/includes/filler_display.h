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
# define FILLER_DISPLAY_H

# include <GLFW/glfw3.h>
# include <GLUT/glut.h>
# include "../libft/libft.h"
# include "get_next_line.h"

# define FORMAT "*.OoxX"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define RESET "\x1B[0m"

# define WIDTH 1000
# define HEIGHT 1000

typedef struct	s_env
{
	int			p1_count;
	int			p2_count;
	int			player;
	char		**map;
	char		**piece;
	int			*piece_size;
	int			*map_size;
	float		sz;
}				t_env;

void			disp_square_red(int x, int y, float sz);
void			disp_square_white(int x, int y, float sz);
void			disp_square_green(int x, int y, float start_y, float sz);
void			disp_square_blue(int x, int y, float sz);
void			get_play(float y, char **str, t_env *e);
char			**get_map(t_env *e, char *line);
char			**get_piece(char *line, t_env *e);
int				*get_size_bonus(char *line, t_env *e);
void			display(GLFWwindow *win, t_env *e);
void			disp_string(float x, float y, char *str);
float			disp_grid(int *size, float start_x, float start_y, float sz);
int				fill_piece_bonus(t_env *e, float start_y);
int				put_map_square(t_env *e);
void			init_env(t_env *e);
GLFWwindow		*init_window(const int resx, const int resy);
void			controls(GLFWwindow *win, int key,
			int scancode, int action, int mods);

#endif
