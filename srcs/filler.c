/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:02:04 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/20 14:50:54 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_player(char *line)
{
	if (strstr(line, "p1"))
		return (1);
	else if (strstr(line, "p2"))
		return (2);
	return (0);
}

void	init_env(t_env *e)
{
	e->player = 0;
	e->piece_size[0] = 0;
	e->piece_size[1] = 0;
	e->map_size[0] = 0;
	e->map_size[1] = 0;
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
			ft_putchar(e->piece[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	e->piece_size[0] = x;
	e->piece_size[1] = y;
	printf("x = %i, y = %i\n", x, y);
	return (0);
}
int check_map(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (e->map[x])
	{
		y = 0;
		while (e->map[x][y])
		{
			ft_putchar(e->map[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	e->map_size[0] = x;
	e->map_size[1] = y;
	printf("x = %i, y = %i\n", x, y);
	return (0);
}

char **get_map(t_env *e)
{
	char	*line;
	int		i;
	int		y;
	char	**map;

	y = 0;
	(void)e;
	map = (char **)malloc(100000);
	while ((get_next_line(0, &line) > 0))
	{
		if (strstr(line, "Piece"))
			break ;
		i = 0;
		while (line[i] && line[i] != '\n' && !strchr(FORMAT, line[i]))
			i++;
		map[y++] = ft_strdup(&line[i]);
	}
	//check_map(map);
	
	return (map);
}

char	get_player_char(int player)
{
	if (player == 1)
		return ('X');
	return ('O');
}

int	*next_star(t_env *e, int piece_coord[2])
{
	printf("PLOPLPOP = %i, %i\n", piece_coord[0], piece_coord[1]);
	while (piece_coord[0] < e->piece_size[0])
	{
		while (++piece_coord[1] < e->piece_size[1])
		{
			if (e->piece[piece_coord[0]][piece_coord[1]] == '*')
				return (piece_coord);
		}
		piece_coord[1] = 0;
		piece_coord[0]++;
	}
	return NULL;
}

int check_stars(t_env *e, int map_coord[2], int piece_coord[2])
{
	int x;
	int y;
	while ((piece_coord = next_star(e, piece_coord)))
	{
		x = map_coord[0] + piece_coord[0];
		y = map_coord[1] + piece_coord[1];
		if (e->map[x][y] != '.')
			return (0);
	}
	return (1);
}

int check_size()
{
	return (1);
}

int check_fill()
{
	return (1);
}

int		test_piece(t_env *e, int map_coord[2])
{
	int	piece_coord[2];
	int x;
	int y;

	x = 0;
	while (x < e->piece_size[0])
	{
		y = 0;
		while (y < e->piece_size[1])
		{
			if (e->piece[x][y] == '*')
			{
				piece_coord[0] = x;
				piece_coord[1] = y;
				if (check_stars(e, map_coord, piece_coord) && check_size() && check_fill())
					printf("PLOP2\n");
			}
			y++;
		}
		x++;
	}
	return (1); // ??
}
	

void	play(t_env *e)
{
	int map_coord[2];

	map_coord[0] = 0;
	while (map_coord[0] <= e->map_size[0]) // < ?
	{
		map_coord[1] = 0;
		while (map_coord[1] <= e->map_size[1])
		{
			if (e->map[map_coord[0]][map_coord[1]] == get_player_char(e->player))
			{
				if (test_piece(e, map_coord))
				{
					printf("start = [%i,%i]\n", map_coord[0], map_coord[1]); // A deplacer
					return ;
				}
			}
			map_coord[1]++;
		}
		map_coord[0]++;
	}
}

int main()
{
	char	*line;
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	printf("START : \n");
	while ((get_next_line(0, &line) > 0))
	{
		if (strstr(line, "$$$"))
			e->player = get_player(line); // Penser a proteger
		if (strstr(line, "Plateau"))
		{
			e->map = get_map(e);
			break ;
			if (!strstr(line, "Piece")) // A verifier
			{
				printf("ERROR\n");
				return (0);
			}
		}
	}
	e->piece = get_map(e);
	check_map(e);
	check_piece(e);
	play(e);
	//printf("coucou\n");
	return (0);
}
