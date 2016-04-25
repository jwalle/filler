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

int	get_player(char *line)
{	
	if (strstr(line, "p1"))
		return (1);	
	else if (strstr(line, "p2"))
		return (2);
	return (0);
}

int	get_size(char *line)
{
	char	**plop;
	int		size;

	plop = ft_strsplit(line, ' ');
	size = ft_atoi(plop[1]);
	free(plop);
	return (size);
}

char **get_piece(char *line)
{
	int		i;
	int		y;
	int		size;
	char	**piece;

	y = 0;
	piece = (char **)malloc(100000);
	//if (strstr(line, "Piece"))
	size = get_size(line);
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

char	get_player_char(int player)
{
	if (player == 1)
		return ('O');
	return ('X');
}