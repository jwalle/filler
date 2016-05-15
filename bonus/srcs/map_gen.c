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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//void set_rand()
//{

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	int i;
	int j;
	int max_i;
	int max_j;
	int flag_X = 0;
	int flag_O = 0;
	int all;

	srand(time(NULL));
	max_i = rand() % 15 + 5;
	max_j = rand() % 20 + 5;
	all = max_i * max_j;

	i = -1;	
	while (++i < max_i)
	{
		j = -1;
		while (++j < max_j)
		{
			all--;
			if (!flag_X && rand() % all == 0)
			{
				ft_putchar('X');
				flag_X++;
			}
			else if (!flag_O && rand() % all == 0)
			{
				ft_putchar('O');
				flag_O++;
			}
			else
				ft_putchar('.');
		}
		ft_putchar('\n');
	}
	return (0);
}
