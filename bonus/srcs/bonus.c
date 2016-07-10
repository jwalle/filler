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

int check_map_bonus(t_env *e)
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
				disp_square_red(y, x);
			else if (e->map[x][y] == 'O')
				disp_square_blue(y, x);
			else if (e->map[x][y] == 'o' || e->map[x][y] == 'x')
				disp_square_white(y, x);
			y++;
		}
		x++;
	}
 	return (0);
}

int fill_piece_bonus(t_env *e, float start_y)
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
				disp_square_green(y, x, start_y);
			y++;
		}
		x++;
	}
 	return (0);
}

void	init_env(t_env *e)
{
	e->player = 0;
	e->piece_size = malloc(sizeof(int) * 2);
	e->map_size = malloc(sizeof(int) * 2);
}

/*
** first value bottom left
** second value bottom right
** third value top right
** fourth value top left
*/

void controls(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

void disp_string(float x, float y, char *str)
{
	int i;

	i = 0;
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2d(x, y);
	while (str[i])
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , str[i++]);
}

GLFWwindow *initWindow(const int resX, const int resY)
{
	GLFWwindow *win;

	if (!glfwInit())
		return (NULL);
	win = glfwCreateWindow(resX, resY, "Filler", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	glfwSetKeyCallback(win, controls);
	printf("Rendrerer : %s\n", glGetString(GL_RENDERER));
	printf("OpenGL version : %s\n", glGetString(GL_VERSION));
	return (win);
}

void display(GLFWwindow *win, t_env *e)
{
	char *line;
	float end_of_map;
	char **got;

	glViewport(0, 0, 1000, 1000);
	glClear(GL_COLOR_BUFFER_BIT);
	end_of_map = 0;
	while ((get_next_line(0, &line) > 0) && !glfwWindowShouldClose(win))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		if (strstr(line, "<got"))
			got = ft_strsplit(line, ' ');
		else if (strstr(line, "Plateau"))
		{
			e->map_size = get_size_bonus(line, e);
			get_next_line(0, &line);
			e->map = get_map(e, line);
			end_of_map = disp_grid(e->map_size, -0.95, 0.95) - 0.1;
			if (e->piece_size[0] > 0)
			{
				disp_string(-1, end_of_map, "Piece :");
				end_of_map -= 0.005;
				disp_grid(e->piece_size, -0.95, end_of_map - 0.10);
				fill_piece_bonus(e, end_of_map - 0.11);
			}

			check_map_bonus(e);			
			if (got != NULL)
				get_play(end_of_map - 0.13, got, e);
			glfwSwapBuffers(win);
			usleep(108000);
		}
		glfwPollEvents();
	}
	glfwTerminate();
}


int	main(int ac, char **av)
{
	GLFWwindow *win;
	t_env *e;
	int width = 1200;
	int height = 1000;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	win = initWindow(1000, 1000);
	if (win)
		display(win, e);
	glfwDestroyWindow(win);
	return (0);
}
