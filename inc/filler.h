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
#define FORMAT ".OoxX"
typedef struct	s_env
{
	int			player;
	char		**map;
	char		**piece;
	int			piece_size[2];
	int			map_size[2];
}				t_env;

#endif
