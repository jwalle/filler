/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 15:51:55 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/24 16:25:04 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_mapgen.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	fill_map(int max_i, int max_j, int all)
{
	int	flag_x;
	int	flag_o;
	int i;
	int j;

	i = -1;
	flag_x = 0;
	flag_o = 0;
	while (++i < max_i)
	{
		j = -1;
		while (++j < max_j)
		{
			all--;
			if (!flag_x && rand() % all == 0)
				flag_x = ft_putchar('X');
			else if (!flag_o && rand() % all == 0)
				flag_o = ft_putchar('O');
			else
				ft_putchar('.');
		}
		ft_putchar('\n');
	}
}

int			main(void)
{
	int max_i;
	int max_j;

	srand(time(NULL));
	max_i = rand() % 15 + 5;
	max_j = rand() % 20 + 5;
	fill_map(max_i, max_j, max_i * max_j);
	return (0);
}
