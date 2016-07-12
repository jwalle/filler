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

float	disp_piece(t_env *e, float eom)
{
	disp_string(-1, eom, "Piece :");
	eom -= 0.005;
	disp_grid(e->piece_size, -0.95, eom - 0.10);
	fill_piece_bonus(e, eom - 0.11);
	return (eom);
}

void	put_winner(t_env *e, float eom)
{
	eom = -0.7;
	disp_string(-1, eom, "And the Winner is :");
	if (e->p1_count > e->p2_count)
		disp_string(-0.1, eom, "Player 1 !!");
	else
		disp_string(-0.1, eom, "Player 2 !!");
}

void	display(GLFWwindow *win, t_env *e)
{
	char	*line;
	float	eom;
	char	**got;

	while (!glfwWindowShouldClose(win)/*&& !glfwGetKey(win, 256)*/)
	{
		if (get_next_line(0, &line) > 0)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			if (strstr(line, "<got"))
				got = ft_strsplit(line, ' ');
			else if (strstr(line, "Plateau"))
			{
				e->map_size = get_size_bonus(line, e);
				get_next_line(0, &line);
				e->map = get_map(e, line);
				eom = disp_grid(e->map_size, -0.95, 0.95);
				if (e->piece_size[0] > 0)
					disp_piece(e, eom);
				check_map_bonus(e);
				if (got != NULL)
					get_play(eom, got, e);
				glfwSwapBuffers(win);
				//usleep(108000);

			}
		}
		else
		{
			put_winner(e, eom);
			glfwSwapBuffers(win);
			// sleep(100);
		}
		glfwPollEvents();
	}
}
