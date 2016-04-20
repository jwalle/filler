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

/* Va chercher la prochaine etoile */

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

/* verifie si les autres etoiles sont sur les '.' */
/* piece_coord == position de l'etoile sur la piece */
/* map_coord == position du X sur la map */

int check_stars(t_env *e, int map_coord[2], int piece_coord[2])
{
	int x;
	int y;

	//x = piece_coord[0];
	//y = piece_coord[1];

	x = 0;
	while (x < piece_size[0])
	{
		y = 0;
		while (y < piece_size[1])
		{
			if (x != piece_coord[0] && y != piece_coord[1])
			{
				if (e->piece[x][y] == '*' && e->map[] // need start of piece
			}
		}
	}

	// while ((piece_coord = next_star(e, piece_coord)))
	// {
	// 	if ((map_coord[0] - piece_coord[0] >= 0) && (map_coord[1] - piece_coord[1] >= 0)
	// 	{
	// 		x = map_coord[0] + piece_coord[0];
	// 		y = map_coord[1] + piece_coord[1];
	// 		if (e->map[x][y] != '.')
	// 			return (0);
	// 	}
	// }
	// return (1);
}

int check_size()
{
	return (1);
}

int check_fill()
{
	return (1);
}

/* Parcours la piece, cherche une etoile et la teste sur la position envoyer par play */

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
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0); // ??
}

/* Parcours la map et cherche les char du joueur */

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
					printf("start = [%i,%i]\n", map_coord[0], map_coord[1]); // A deplacer, doit renvoyer debut piece
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
