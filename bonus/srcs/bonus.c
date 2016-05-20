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

#include "../inc/filler.h"
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>


#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

#define WIDTH 1200
#define HEIGHT 1000

void disp_square_red(int x, int y)
{
	float x1;
	float y1;
	float size = 0.03;

	x1 = -0.94 + ((float)x * 0.05);
	y1 = 0.94 - ((float)y * 0.05);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1,y1 - size,-1.0f);
	glVertex3f(x1,y1,-1.0f);
	glVertex3f(x1 + size,y1,-1.0f);
	glVertex3f(x1 + size,y1 - size,-1.0f);
	glEnd();
}

void disp_square_white(int x, int y)
{
	float x1;
	float y1;
	float size = 0.03;

	x1 = -0.94 + ((float)x * 0.05);
	y1 = 0.94 - ((float)y * 0.05);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1,y1 - size,-1.0f);
	glVertex3f(x1,y1,-1.0f);
	glVertex3f(x1 + size,y1,-1.0f);
	glVertex3f(x1 + size,y1 - size,-1.0f);
	glEnd();
}

void disp_square_green(int x, int y, float start_y)
{
	float x1;
	float y1;
	float size = 0.03;

	x1 = -0.94 + ((float)x * 0.05);
	y1 = start_y - ((float)y * 0.05);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1,y1 - size,-1.0f);
	glVertex3f(x1,y1,-1.0f);
	glVertex3f(x1 + size,y1,-1.0f);
	glVertex3f(x1 + size,y1 - size,-1.0f);
	glEnd();
}


void disp_square_blue(int x, int y)
{
	float x1;
	float y1;
	float size = 0.03;

	x1 = -0.94 + ((float)x * 0.05);
	y1 = 0.94 - ((float)y * 0.05);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1,y1 - size,-1.0f);
	glVertex3f(x1,y1,-1.0f);
	glVertex3f(x1 + size,y1,-1.0f);
	glVertex3f(x1 + size,y1 - size,-1.0f);
	glEnd();
}

void ft_putchar_color(char c, char *str)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putstr(RESET);
}

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

int	*get_size_bonus(char *line, t_env *e)
{
	char	**plop;
	int		*size;

	size = (int *)malloc(sizeof(int) * 2);
	plop = ft_strsplit(line, ' ');
	size[0] = ft_atoi(plop[1]);
	size[1] = ft_atoi(plop[2]);
	free(plop);
	return (size);
}

char **get_piece(char *line, t_env *e)
{
	int		i;
	int		y;
	int		size;
	char	**piece;

	y = 0;
	piece = (char **)malloc(100000);
	e->piece_size = get_size_bonus(line, e);
	size = e->piece_size[0];
	while (size--)
	{
		get_next_line(0, &line);
		i = 0;
		while (line[i] && line[i] != '\n' && !strchr(FORMAT, line[i]))
			i++;
		piece[y++] = ft_strdup(&line[i]);
	}
	return (piece);
}

char **get_map(t_env *e, char *line)
{
	int		i;
	int		y;
	char	**map;

	y = 0;
	map = (char **)malloc(100000);
	i = 0;
	while ((get_next_line(0, &line) > 0))
	{
		i = 0;
		if (strstr(line, "Piece"))
		{
			e->piece = get_piece(line, e);			
			return (map);
		}
		//while (line[i] && !strchr(FORMAT, line[i]))
		while (ft_isdigit(line[i]))
			i++;
		i++;
		printf("LINE = %s\n", line);

		map[y++] = ft_strdup(&line[i]);
	}
	return (map);
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
void disp_line(float x1, float y1, float x2, float y2)
{
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2d(x1 , y1); // point haut (x + col, y ->)
		glVertex2d(x2 , y2); // point bas (x + col, y ->)
		glEnd();
}

void controls(GLFWwindow *win, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

void disp_number(float x, float y, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa(n);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2d(x, y);
	while (str[i])
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i++]);
}

float	disp_grid(int *size, float start_x, float start_y)
{
	int col;
	int line;
	float max_col;
	float max_line;

	col = size[1];
	line = size[0];
	// printf("size = (%i,%i) | start = (%f,%f)\n", size[0] ,size[1], start_x, start_y);
	max_col = start_y - (line * 0.05);
	max_line = start_x + (col * 0.05);
	while (col)
	{
		disp_line(start_x + 0.05 * (float)(col % size[1]), start_y, start_x + 0.05 * (float)(col % size[1]), max_col);
		disp_number(start_x + 0.015 + 0.05 * (float)(col % size[1]), start_y + 0.01, col % size[1]);
		col--;
	}
	disp_line(start_x + 0.05 * (float)size[1] ,start_y, start_x + 0.05 * (float)size[1], max_col);
	while (line)
	{
		disp_line(start_x, start_y - 0.05 * (float)(line % size[0]), max_line, start_y - 0.05 * (float)(line % size[0]));
		disp_number(-1.0 , start_y - 0.04 - 0.05 * (float)(line % size[0]), line % size[0]);
		line--;
	}
	disp_line(start_x, start_y - 0.05 * (float)size[0] ,max_line, start_y - 0.05 * (float)size[0]);
	return(max_col);
}

void disp_piece(t_env *e)
{

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

void disp_msg(void)
{
	disp_square_blue(0, 0);
}

void display(GLFWwindow *win, t_env *e)
{
	char *line;
	float end_of_map;

	glViewport(0, 0, 1000, 1000);
	glClear(GL_COLOR_BUFFER_BIT);
	//disp_msg();
	while ((get_next_line(0, &line) > 0) && !glfwWindowShouldClose(win))
	{	
		if (strstr(line, "Plateau"))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			e->map_size = get_size_bonus(line, e);
			get_next_line(0, &line);
			e->map = get_map(e, line);
			end_of_map = disp_grid(e->map_size, -0.95, 0.95);
			if (e->piece_size[0] > 0)
			{
				disp_grid(e->piece_size, -0.95, end_of_map - 0.1);
				fill_piece_bonus(e, end_of_map - 0.11);
			}
			check_map_bonus(e);
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
	//glutInit(&ac, av);
	if (win)
		display(win, e);

	glfwDestroyWindow(win);
	//while ()
			//glfwGetFramebufferSize(win, &width, &height);
		
	return (0);
}
