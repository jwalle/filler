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

int	main()
{
	int i;
	int j;
	//char *str;
	char *line;

	initscr();
	//start_color();
	//COLOR_PAIRS = 2049;
	//ft_init_color();
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
			mvprintw(j, i, &line[i]);
			i++;
		}
		j++;
	}
	refresh();
	return (0);
}
