/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:02:04 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/21 16:40:44 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		test_piece(t_env *e, int map_coord[2])
{
	int	star_coord[2];
	int piece_coord[2];
	int x;
	int y;

	x = -1;
	while (++x < e->piece_size[0])
	{
		y = -1;
		while (++y < e->piece_size[1])
		{
			if (!e->piece[x][y])
				exit (-1);
			if (e->piece[x][y] == '*')
			{
				star_coord[0] = x;
				star_coord[1] = y;
				piece_coord[0] = map_coord[0] - star_coord[0];		
				piece_coord[1] = map_coord[1] - star_coord[1];
				if (check_fill(piece_coord) &&						// check if we are still on the map... ?
					check_stars(e, piece_coord, star_coord) &&		// check if all (but the one) star is on empty space.
					check_size(e, piece_coord))						// check if all the piece is on the map
					return (put_result(piece_coord)); 				//TODO ALGO FIND & DESTROY
			}
		}
	}
	return (0);
}

void	find(t_env *e)
{
	int map_coord[2];

	map_coord[0] = -1;
	while (++map_coord[0] < e->map_size[0])
	{
		map_coord[1] = -1;
		while (++map_coord[1] < e->map_size[1])
		{
			if (e->map[map_coord[0]][map_coord[1]] == get_other_char(e->player))
			{
				e->find = map_coord;
				return ;
			}
		}
	}
	ft_putstr("ERROR\n");
	exit(1);
}

void	play(t_env *e)
{
	int map_coord[2];

	map_coord[0] = -1;
	find(e);
	while (++map_coord[0] < e->map_size[0])
	{
		map_coord[1] = -1;
		while (++map_coord[1] < e->map_size[1])
		{
			if (e->map[map_coord[0]][map_coord[1]]
				== get_player_char(e->player))
			{
				if (test_piece(e, map_coord))
					return ;
			}
		}
	}
	out_of_play();
}

int		main(void)
{
	char	*line;
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	while (get_next_line(0, &line) > 0)
	{
		if (strstr(line, "$$$") && !e->player)
			e->player = get_player(line);
		if (strstr(line, "Plateau"))
		{
			e->map = get_map(e, line);
			if (e->map)
				play(e);
		}
	}
	destroy_env(e);
	return (0);
}
