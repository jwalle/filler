/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 19:16:41 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/10 19:16:52 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_display.h"

void		init_env(t_env *e)
{
	e->player = 0;
	e->p1_count = 0;
	e->p2_count = 0;
	e->piece_size = malloc(sizeof(int) * 2);
	e->map_size = malloc(sizeof(int) * 2);
}

void		destroy_env(t_env *e)
{
	e->player = 0;
	e->p1_count = 0;
	e->p2_count = 0;
	free(e->piece_size);
	free(e->map_size);
}

void		controls(GLFWwindow *win, int key, int scancode,
				int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(win, GL_TRUE);
	}
}

GLFWwindow	*init_window(const int resx, const int resy)
{
	GLFWwindow *win;

	if (!glfwInit())
		return (NULL);
	win = glfwCreateWindow(resx, resy, "Filler", NULL, NULL);
	if (!win)
	{
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	glfwSetKeyCallback(win, controls);
	return (win);
}
