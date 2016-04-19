/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:02:04 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/19 17:55:43 by jwalle           ###   ########.fr       */
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
			e->player = get_player(line); // Penser a proteger.)
		printf("LINE = %s\n", line);
	}
		//printf("coucou\n");
	return (0);
}
