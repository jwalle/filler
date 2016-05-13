/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 12:23:28 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/24 12:23:36 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* verifie si les autres etoiles sont sur les '.' */
/* star_coord == position de l'etoile sur la piece */
/* map_coord == position du X sur la map */
/* piece_coord == position de la piece sur la map */

int check_stars(t_env *e, int piece_coord[2], int star_coord[2])
{
	int x;
	int y;

	x = 0;
	while ((x < e->piece_size[0]) && (piece_coord[0] + x < e->map_size[0]))
	{
		y = 0;	
		while ((y < e->piece_size[1]) && (piece_coord[1] + y < e->map_size[1]))
		{
			if (x != star_coord[0] || y != star_coord[1])
			{
				if (e->piece[x][y] == '*' && e->map[piece_coord[0] + x][piece_coord[1] + y] != '.')
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int check_size(t_env *e, int piece_coord[2])
{
	if ((piece_coord[0] + e->piece_size[0]) > e->map_size[0])
		return (0);
	if ((piece_coord[1] + e->piece_size[1]) > e->map_size[1])
		return (0);
	return (1);
}

int check_fill(int piece_coord[2])
{
	if (piece_coord[0] < 0 || piece_coord[1] < 0)
		return (0);
	return (1);
}

int check_piece(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (e->piece[x])
	{
		y = 0;
		while (e->piece[x][y])
		{
			// ft_putchar(e->piece[x][y]);
			y++;
		}
		// ft_putchar('\n');
		x++;
	}
	e->piece_size[0] = x;
	e->piece_size[1] = y;
	//printf("x = %i, y = %i\n", x, y);
	return (0);
}

int check_map(t_env *e)
{
	int x;
	int y = 0;

	x = 0;
	while (x < e->map_size[0])
	{
		y = 0;
		//ft_putstr_fd(e->map[x], 2);
		while (y < e->map_size[1])
		{
			//ft_putchar(e->map[x][y]);
			y++;
		}
		//ft_putchar_fd('\n', 2);
		x++;
	}
	//e->map_size[0] = x;
	//e->map_size[1] = y;
	//printf("x = %i, y = %i\n", x, y);
	return (0);
}
