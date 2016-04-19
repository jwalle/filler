/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:02:04 by jwalle            #+#    #+#             */
/*   Updated: 2016/04/19 18:10:48 by jwalle           ###   ########.fr       */
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

char **get_map(t_env *e)
{
	char	*line;
	int		i;
	int		x;
	int		y;


	y = 0;
	(void)e;
	while ((get_next_line(0, &line) > 0))
	{
		x = 0;
		i = 0;
		while (line[i] && line[i] != "\n" && !strchr(FORMAT, line[i]))
			i++;
		while (strchr(FORMAT, line[i]))
		{




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
		if (strstr(line, "Plateau"))
			e->map = get_map(e);
		printf("LINE = %s\n", line);
	}
		//printf("coucou\n");
	return (0);
}
