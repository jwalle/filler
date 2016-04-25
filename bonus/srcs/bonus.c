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
#include <curses.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void ft_putchar_color(char c, char *str)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putstr(RESET);
}

static void		ft_init_color(void)
{
	init_color(COLOR_RED, 500, 300, 200);
	init_color(COLOR_MAGENTA, 304, 200, 209);
	init_color(COLOR_CYAN, 304, 222, 100);
	init_color(COLOR_WHITE, 155 * 4, 160 * 4, 160 * 4);
	init_pair(1, COLOR_RED, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_BLACK, COLOR_YELLOW);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(16, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(32, COLOR_BLACK, COLOR_CYAN);
	init_pair(64, COLOR_YELLOW, COLOR_CYAN);
	init_pair(128, COLOR_RED, COLOR_CYAN);
	init_pair(256, COLOR_MAGENTA, COLOR_RED);
	init_pair(512, COLOR_YELLOW, COLOR_BLACK);
	init_pair(1024, COLOR_YELLOW, COLOR_GREEN);
	init_pair(2048, COLOR_YELLOW, COLOR_WHITE);
}

int check_map(t_env *e)
{
	int x;
	int y;
	int i;
	int len;

	x = 0;
	i = 0;
	while (e->map[x])
	{
		y = 0;
		len = strlen(e->map[x]) * 4;
		while (len--)
			mvprintw(x + i, len, "_");
		i++;
		while (e->map[x][y])
		{
			if (e->map[x][y] == 'X')
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
				attron(COLOR_PAIR(16));
				mvprintw(x + i, y * 4, "| . ");
				attroff(COLOR_PAIR(16));
			}
			mvprintw(x + i, y * 4, "|");
			//ft_putchar_fd(e->map[x][y], 2);
			y++;
		}
		mvprintw(x, y  * 4, "\n");
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
		while (line[i] && !strchr(FORMAT, line[i]))
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
	//int size[2];
	int j;
	t_env *e;
	//char *str;
	char *line;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	initscr();
	start_color();
	
	COLOR_PAIRS = 2049;
	ft_init_color();
	//curs_set(0);
	//getmaxyx(stdscr, toto.row, toto.col);
	//toto.size_board = 100; // ?
	//toto.x = 1; // cell size
	j = 0;
	while (get_next_line(0, &line) > 0)
	{
		i = 0;
		while (line[i])
		{
			if (strstr(line, "Plateau"))
			{
				//get_size_bonus(line, size);
				e->map = get_map(e, line);
				check_map(e);
				refresh();
			}
			//mvprintw(j, i, &line[i]);
			i++;
		}
		j++;
		sleep(1);
		getch();
	}
	endwin();
	return (0);
}
