/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:33:59 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/10 17:34:07 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_display.h"

void	disp_square_red(int x, int y, float sz)
{
	float x1;
	float y1;
	float size;

	size = sz / 2;
	x1 = (-1.0 + (sz * 1.9)) + ((float)x * sz);
	y1 = (1.0 - (sz * 1.9)) - ((float)y * sz);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1 - size, -1.0f);
	glVertex3f(x1, y1, -1.0f);
	glVertex3f(x1 + size, y1, -1.0f);
	glVertex3f(x1 + size, y1 - size, -1.0f);
	glEnd();
}

void	disp_square_white(int x, int y, float sz)
{
	float x1;
	float y1;
	float size;

	size = sz / 2;
	x1 = (-1.0 + (sz * 1.9)) + ((float)x * sz);
	y1 = (1.0 - (sz * 1.9)) - ((float)y * sz);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1 - size, -1.0f);
	glVertex3f(x1, y1, -1.0f);
	glVertex3f(x1 + size, y1, -1.0f);
	glVertex3f(x1 + size, y1 - size, -1.0f);
	glEnd();
}

void	disp_square_green(int x, int y, float start_y, float sz)
{
	float x1;
	float y1;
	float size;

	size = sz / 2;
	x1 = (-1.0 + (sz * 1.9)) + ((float)x * sz);
	y1 = (1.0 - (sz * 1.9)) - ((float)y * sz);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1 - size, -1.0f);
	glVertex3f(x1, y1, -1.0f);
	glVertex3f(x1 + size, y1, -1.0f);
	glVertex3f(x1 + size, y1 - size, -1.0f);
	glEnd();
}

void	disp_square_blue(int x, int y, float sz)
{
	float x1;
	float y1;
	float size;

	size = sz / 2;
	x1 = (-1.0 + (sz * 1.9)) + ((float)x * sz);
	y1 = (1.0 - (sz * 1.9)) - ((float)y * sz);
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(x1, y1 - size, -1.0f);
	glVertex3f(x1, y1, -1.0f);
	glVertex3f(x1 + size, y1, -1.0f);
	glVertex3f(x1 + size, y1 - size, -1.0f);
	glEnd();
}
