/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 18:32:18 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/10 18:32:37 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_display.h"

float disp_piece(t_env *e, int eom)
{
	disp_string(-1, eom, "Piece :");
	eom -= 0.005;
	disp_grid(e->piece_size, -0.95, eom - 0.10);
	fill_piece_bonus(e, eom - 0.11);	
	return (eom);
}

void display(GLFWwindow *win, t_env *e)
{
	char *line;
	float eom;
	char **got;

	while ((get_next_line(0, &line) > 0) && !glfwWindowShouldClose(win))
	{	
		glClear(GL_COLOR_BUFFER_BIT);
		if (strstr(line, "<got"))
			got = ft_strsplit(line, ' ');
		else if (strstr(line, "Plateau"))
		{
			e->map_size = get_size_bonus(line, e);
			get_next_line(0, &line);
			e->map = get_map(e, line);
			eom = disp_grid(e->map_size, -0.95, 0.95) - 0.1;
			if (e->piece_size[0] > 0)
				eom = disp_piece(e, eom);
			check_map_bonus(e);
			if (got != NULL)
				get_play(eom - 0.13, got, e);
			glfwSwapBuffers(win);
			usleep(108000);
		}
		glfwPollEvents();
	}
}
