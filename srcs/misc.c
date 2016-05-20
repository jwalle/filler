/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 12:30:39 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/24 12:30:46 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	debug(char *line) //A RETIRER
{
	ft_putstr_fd("LINE = ", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("						<--DEBUG\n", 2);
}



void	init_env(t_env *e)
{
	e->player = 0;

	e->piece_size = malloc(sizeof(int) * 2);
	e->map_size = malloc(sizeof(int) * 2);
}

int		put_result(int piece_coord[2])
{
	ft_putnbr(piece_coord[0]);
	ft_putchar(' ');
	ft_putnbr(piece_coord[1]);
	ft_putchar('\n');
	return (1);
}

void	out_of_play()
{
	ft_putstr("0 0\n");
}
