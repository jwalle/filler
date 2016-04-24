/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:36:24 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/24 14:40:50 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void ft_putchar_color(char c, char *str)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putstr(RESET);
}

int	main()
{
	int i;
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == 'X')
				ft_putchar_color('X', RED);
			else if (line[i] == 'O')
				ft_putchar_color('O', GREEN);
			else if (strstr(line, "Plateau"))
			{
				system("clear");
			}
			else
				ft_putchar(line[i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
