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

#include "filler.h"
#include <GLFW/glfw3.h>
# include <GLUT/glut.h>


#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

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
	while (x <= size[0])
	{
		y = 0;
		if (!e->map[x])
			return (0);
		len = strlen(e->map[x]) * 4;
		i++;
		y = 0;
		while (y <= size[1])
		{
			/*if (e->map[x][y] == 'X')
			{
				attron(COLOR_PAIR(4));
				mvprintw(x + i, y * 4, "| X ");
				attroff(COLOR_PAIR(4));
			}
			else if (e->map[x][y] == 'O')
			{
				attron(COLOR_PAIR(8));
				mvprintw(x + i, y * 4, "| O ");
				attroff(COLOR_PAIR(32));
			}
			else if (e->map[x][y] == '.')
			{
				attron(COLOR_PAIR(32));
				mvprintw(x + i, y * 4, "| . ");
				attroff(COLOR_PAIR(32));
			}
			else if (e->map[x][y] == 'o')
			{
				attron(COLOR_PAIR(64));
				mvprintw(x + i, y * 4, "| o ");
				attroff(COLOR_PAIR(64));
			}
			else if (e->map[x][y] == 'x')
			{
				attron(COLOR_PAIR(64));
				mvprintw(x + i, y * 4, "| x ");
				attroff(COLOR_PAIR(64));
			}
			mvprintw(x + i, y * 4, "|");*/
			//ft_putchar_fd(e->map[x][y], 2);
			y++;
		}
		//ft_putchar_fd('\n', 2);
		x++;
	}
	e->map_size[0] = x;
	e->map_size[1] = y;
	//printf("x = %i, y = %i\n", x, y);
	return (0);
}

void	get_size_bonus(char *line, int size[2])
{
	char	**plop;

	plop = ft_strsplit(line, ' ');
	size[0] = ft_atoi(plop[1]);
	size[1] = ft_atoi(plop[2]);
 	free(plop);
}

char **get_piece(char *line)
{
	int		i;
	int		y;
	int		size[2];
	char	**piece;

	y = 0;
	piece = (char **)malloc(100000);
	//if (strstr(line, "Piece"))
	get_size_bonus(line, size);
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
	get_next_line(0, &line);
	while ((get_next_line(0, &line) > 0))
	{
		if (strstr(line, "Piece"))
		{
			e->piece = get_piece(line);
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
	e->piece_size[0] = 0;
	e->piece_size[1] = 0;
	e->map_size[0] = 0;
	e->map_size[1] = 0;
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

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	if (!glfwInit())
		return (-1);
	win = glfwCreateWindow(640, 480, "Filler", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(win);
	while ((get_next_line(0, &line) > 0) && !glfwWindowShouldClose(win)) 
	{
		i = 0;
		while (line[i])
		{
			if (strstr(line, "Plateau"))
			{
				get_size_bonus(line, size);
				e->map = get_map(e, line);
				check_map_bonus(e, size);
			}
			i++;

		}
		j++;
		glfwSwapBuffers(win);
		glfwPollEvents();
	}
	glfwTerminate();
	return (0);
}
