/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:00:20 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/20 14:11:32 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"
#define FORMAT "*.OoxX"

typedef struct	s_env
{
	int			player;
	char		**map;
	char		**piece;
	int			*piece_size;
	int			*map_size;
}				t_env;

void			init_env(t_env *e);
void			out_of_play();
int				put_result(int piece_coord[2]);
void			debug(char *line);
int				get_player(char *line);
int				*get_size(char *line);
char			**get_piece(char *line, t_env *e);
char			**get_map(t_env *e, char *line);
char			get_player_char(int player);
int				check_stars(t_env *e, int piece_coord[2], int star_coord[2]);
int				check_size(t_env *e, int piece_coord[2]);
int				check_fill(int piece_coord[2]);
int				check_piece(t_env *e);
int				check_map(t_env *e);
void			destroy_env(t_env *e);

#endif
