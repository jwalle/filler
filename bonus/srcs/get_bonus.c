/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:38:40 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/10 17:38:57 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_display.h"

int		*get_size_bonus(char *line, t_env *e)
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

char	**get_piece(char *line, t_env *e)
{
	int		i;
	int		y;
	int		size;
	char	**piece;

	y = 0;
	piece = (char **)malloc(100000);
	e->piece_size = get_size_bonus(line, e);
	size = e->piece_size[0];
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

char	**get_map(t_env *e, char *line)
{
	int		i;
	int		y;
	char	**map;

	y = 0;
	i = 0;
	map = (char **)malloc(100000);
	while ((get_next_line(0, &line) > 0))
	{
		i = 0;
		if (strstr(line, "Piece"))
		{
			e->piece = get_piece(line, e);
			return (map);
		}
		while (ft_isdigit(line[i]))
			i++;
		i++;
		map[y++] = ft_strdup(&line[i]);
	}
	return (map);
}

void	get_play(float y, char **str, t_env *e)
{
	int		player;
	float	x;

	x = -1.0;
	y = y - (float)(2 + e->piece_size[0]) * 0.05;
	if (!strcmp(str[1], "(O):"))
	{
		e->p1_count++;	
		disp_string(x, y, "Player 1 turn :");
	}
	else if (!strcmp(str[1], "(X):"))
	{
		e->p2_count++;	
		disp_string(x, y, "Player 2 turn :");
	}
	disp_string(x + 0.25, y, str[2]);
	disp_string(x + 0.3, y, str[3]);
	disp_string(x, y - 0.05 , "Player 1 score :");
	disp_string(x + 0.27, y - 0.05 , ft_itoa(e->p1_count));
	disp_string(x, y - 0.1 , "Player 2 score :");
	disp_string(x + 0.27, y - 0.1 , ft_itoa(e->p2_count));
}
