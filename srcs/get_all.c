/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 12:23:01 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/24 12:23:14 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(char *line)
{
	if (ft_strstr(line, "p1"))
		return (1);
	else if (ft_strstr(line, "p2"))
		return (2);
	return (0);
}

int		*get_size(char *line)
{
	char	**plop;
	int		*size;

	size = (int *)malloc(sizeof(int) * 2);
	plop = ft_strsplit(line, ' ');
	if (!plop[1] || !plop[2])
		return (NULL);
	size[0] = ft_atoi(plop[1]);
	size[1] = ft_atoi(plop[2]);
	free(plop);
	return (size);
}

char	**get_piece(char *line, t_env *e)
{
	int		i;
	int		y;
	int		size;
	char	**piece;

	y = 0;
	piece = (char **)malloc(100000);
	if (!(e->piece_size = get_size(line)))
		return (NULL);
	size = e->piece_size[0];
	while (size--)
	{
		i = 0;
		get_next_line(0, &line);
		while (line[i] && line[i] != '\n' && !ft_strchr(FORMAT, line[i]))
			i++;
		piece[y++] = ft_strdup(&line[i]);
	}
	return (piece);
}

char	**get_map(t_env *e, char *line)
{
	int		i;
	int		y;
	char	**map;

	y = 0;
	map = (char **)malloc(100000);
	if (!(e->map_size = get_size(line)))
		return (NULL);
	get_next_line(0, &line);
	while ((get_next_line(0, &line) > 0))
	{
		if (ft_strstr(line, "Piece"))
		{
			if ((e->piece = get_piece(line, e)))
				return (map);
			else
				return (NULL);
		}
		i = 0;
		while (line[i] && !ft_strchr(FORMAT, line[i]))
			i++;
		map[y++] = ft_strdup(&line[i]);
		if ((int)ft_strlen(&line[i]) < e->map_size[1])
			return (NULL);
	}
	if (y < e->map_size[1])
		return (NULL);
	return (map);
}

char	get_other_char(int player)
{
	if (player == 1)
		return ('X');
	return ('O');
}

char	get_player_char(int player)
{
	if (player == 1)
		return ('O');
	return ('X');
}
