/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:43:01 by jwalle            #+#    #+#             */
/*   Updated: 2016/07/10 17:43:16 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_display.h"

void	disp_line(float x1, float y1, float x2, float y2)
{
//	if (x1 > WIDTH || x2 > WIDTH || y1 > WIDTH || y2 > WIDTH)
//		printf("PLOOOPPP\n");
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

void	disp_number(float x, float y, int n, int line)
{
	char	*str;
	int		i;

	if (x > WIDTH || y > WIDTH)
		printf("PLOOOPPP\n");
	i = 0;
	str = ft_itoa(n);
	glColor3f(1.0f, 1.0f, 1.0f);
	if (n > 9 && !line)
		x -= 0.01;
	glRasterPos2d(x, y);
	while (str[i])
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i++]);
	free(str);
}

void	disp_coll(float start_x, float start_y, int *size, float sz)
{
	int		col;
	int		line;
	float	max_col;

	line = size[0];
	col = size[1];
	max_col = start_y - (line * sz);
	while (col)
	{
		disp_line(start_x + sz * (float)(col % size[1]), start_y,
			start_x + sz * (float)(col % size[1]), max_col);
		/*disp_number(start_x + 0.015 + sz * (float)(col % size[1]),
			start_y + 0.01, col % size[1], 0);*/
		col--;
	}
}

float	disp_grid(int *size, float start_x, float start_y, float sz)
{
	int		col;
	int		line;
	float	max_col;
	float	max_line;

	col = size[1];
	line = size[0];
	max_col = start_y - (line * sz);
	max_line = start_x + (col * sz);
	disp_coll(start_x, start_y, size, sz);
	disp_line(start_x + sz * (float)size[1], start_y,
		start_x + sz * (float)size[1], max_col);
	while (line)
	{
		disp_line(start_x, start_y - sz * (float)(line % size[0]),
			max_line, start_y - sz * (float)(line % size[0]));
		/*disp_number(-1.0, start_y - 0.04 - sz * (float)(line % size[0]),
			line % size[0], 1);*/
		line--;
	}
	disp_line(start_x, start_y - sz * (float)size[0],
		max_line, start_y - sz * (float)size[0]);
	return (max_col - 0.1);
}
