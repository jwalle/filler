/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:36:24 by jwalle            #+#    #+#             */
/*   Updated: 2016/05/20 12:59:21 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_display.h"

int		put_map_square(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (x < e->map_size[0])
	{
		if (!e->map[x])
			return (0);
		y = 0;
		while (y < e->map_size[1])
		{
			if (e->map[x][y] == 'X')
				disp_square_red(y, x, e->sz);
			else if (e->map[x][y] == 'O')
				disp_square_blue(y, x, e->sz);
			else if (e->map[x][y] == 'o' || e->map[x][y] == 'x')
				disp_square_white(y, x, e->sz);
			y++;
		}
		free(e->map[x]);
		x++;
	}
	free(e->map);
	return (0);
}

int		fill_piece_bonus(t_env *e, float start_y)
{
	int x;
	int y;

	x = 0;
	while (x < e->piece_size[0])
	{
		if (!e->piece[x])
			return (0);
		y = 0;
		while (y < e->piece_size[1])
		{
			if (e->piece[x][y] == '*')
				disp_square_green(y, x, start_y, e->sz);
			y++;
		}
		free(e->piece[x]);
		x++;
	}
	free(e->piece);
	return (0);
}

/*
** first value bottom left
** second value bottom right
** third value top right
** fourth value top left
*/

void	disp_string(float x, float y, char *str)
{
	int i;

	i = 0;
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2d(x, y);
	while (str[i])
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i++]);
}

int		main(int ac, char **av)
{
	GLFWwindow	*win;
	t_env		*e;
	int			width;
	int			height;

	width = WIDTH;
	height = HEIGHT;
	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	win = init_window(WIDTH, HEIGHT);
	if (win)
	{
		glViewport(0, 0, WIDTH, HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT);
		display(win, e);
		glfwTerminate();
	}
	glfwDestroyWindow(win);
	return (0);
}
