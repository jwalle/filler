/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:36:24 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/24 16:26:21 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"
#include <GLFW/glfw3.h>
//#include <GLUT/glut.h>


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

int check_map_bonus(t_env *e, int size[2])
{
	int x;
	int y;
	int i;
	int len;

	x = 0;
	i = 0;
	while (x < e->map_size[0])
	{
		y = 0;
		if (!e->map[x])
			return (0);
		len = strlen(e->map[x]) * 4;
		i++;
		y = 0;
		while (y < e->map_size[1])
		{
			if (e->map[x][y] == 'X')
				disp_square_red(x, y);
			else if (e->map[x][y] == 'O')
				disp_square_blue(x, y);
			else if (e->map[x][y] == 'o' || e->map[x][y] == 'x')
				disp_square_white(x, y);
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
	int		*size;
	char	**piece;

	y = 0;
	piece = (char **)malloc(100000);
	//if (strstr(line, "Piece"))
	e->piece_size = get_size_bonus(line, e);
	size = e->piece_size;
	while (size[0]--)
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
	e->map_size = get_size_bonus(line, e);
	get_next_line(0, &line);
	while ((get_next_line(0, &line) > 0))
	{
		if (strstr(line, "Piece"))
		{
			e->piece = get_piece(line, e);
			return (map);
		}
		i = 0;
		//while (line[i] && !strchr(FORMAT, line[i]))
		while (ft_isdigit(line[i]))
			i++;
		i++;
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

void disp_grid(int *size)
{
	float x;
	int col;
	int line;
	float max_col;
	float max_line;

	x = 0;
	col = size[0];
	line = size[1];
	max_col = 0.95 - (line * 0.05);
	max_line = -0.95 + (col * 0.05);
	while (col)
	{
		disp_line(-0.95 + 0.05 * (float)(col % size[0]), 0.95, -0.95 + 0.05 * (float)(col % size[0]), max_col);
		// glColor3f(1.0f, 1.0f, 1.0f);
		// glBegin(GL_LINE_LOOP);
		// glVertex2d(-0.95 + 0.05 * (float)(col % size[0]) , 0.95); // point haut (x + col, y ->)
		// glVertex2d(-0.95 + 0.05 * (float)(col % size[0]) , max_col); // point bas (x + col, y ->)
		// glEnd();
		col--;
	}
	disp_line(-0.95 + 0.05 * (float)(size[0]) ,0.95, -0.95 + 0.05 * (float)(size[0]),max_col);
	while (line)
	{
		disp_line(-0.95, 0.95 - 0.05 * (float)(line % size[1]), max_line, 0.95 - 0.05 * (float)(line % size[1]));
		// glColor3f(1.0f, 1.0f, 1.0f);
		// glBegin(GL_LINE_LOOP);
		// glVertex2d(-0.95 , 0.95 - 0.05 * (float)(line % size[1])); // point gauche (x + col, y ->)
		// glVertex2d(max_line , 0.95 - 0.05 * (float)(line % size[1])); // point droit (x + col, y ->)
		// glEnd();
		line--;
	}
	disp_line(-0.95, 0.95 - 0.05 * (float)size[1] ,max_line,0.95 - 0.05 * (float)size[1]);
	disp_square_red(2, 2);
}

int	main()
{
	int i;
	int size[2];
	int j = 0;
	GLFWwindow *win;
	t_env *e;
	//char *str;
	char *line;
	int width = 1200;
	int height = 1000;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	if (!glfwInit())
		return (-1);
	win = glfwCreateWindow(1200, 1000, "Filler", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(win);
	while (!glfwWindowShouldClose(win))
	{
		while ((get_next_line(0, &line) > 0)) 
		{		
			glfwGetFramebufferSize(win, &width, &height);
			glViewport(0, 0, 1200, 1000);
		
			glClear(GL_COLOR_BUFFER_BIT);
			i = 0;
			while (line[i])
			{
				if (strstr(line, "Plateau"))
				{
					get_size_bonus(line, e);
					e->map = get_map(e, line);
					disp_grid(e->map_size);
					check_map_bonus(e, size);
				}
				i++;
			}
			j++;
			glfwSwapBuffers(win);
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return (0);
}
