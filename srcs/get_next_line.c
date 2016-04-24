/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 17:44:58 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/13 16:40:06 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void				ft_buf_to_tmp(int rd, char *buf, char **tmp)
{
	char			*sw;

	buf[rd] = '\0';
	sw = *tmp;
	*tmp = ft_strjoin(sw, buf);
	ft_strdel(&sw);
}

void				ft_tmp_to_line(char **line, char **tmp)
{
	char			*buf;
	int				len;

	len = ft_strlen(*tmp) - ft_strlen(ft_strchr(*tmp, '\n'));
	*line = ft_strsub(*tmp, 0, len);
	buf = *tmp;
	*tmp = ft_strdup(ft_strchr(*tmp, '\n') + 1);
	ft_strdel(&buf);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				rd;
	static char		*tmp;

	rd = 0;
	if (!line || fd < 0)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(0);
	while (!(ft_strchr(tmp, '\n')) && (rd = read(fd, buf, BUFF_SIZE)) > 0)
		ft_buf_to_tmp(rd, buf, &tmp);
	if (rd < 0)
		return (-1);
	if (!(ft_strchr(tmp, '\n')))
	{
		if (!(rd))
		{
			*line = tmp;
			tmp = NULL;
			return (0);
		}
	}
	ft_tmp_to_line(line, &tmp);
	return (1);
}

/*
char	*ft_strndup(const char *s1, int k)
{
	int		i;
	char	*dest;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (NULL);
	if ((dest = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (s1[i] != '\0' && i < k)
	{
		dest[i] = s1[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

int		ft_set_zero(t_static *toto)
{
	if (toto->cpy >= toto->size)
	{
		toto->cpy = 0;
		toto->size = 0;
		return (0);
	}
	return (1);
}

int		ft_cpy(t_static *toto, char **line)
{
	int		k;
	char	*temp;

	k = 0;
	if (!ft_set_zero(toto))
		return (0);
	while (toto->buf[k] != '\0' && toto->buf[k] != '\n' && toto->buf[k] != EOF)
		k++;
	*line = ft_strndup(toto->buf, k);
	toto->cpy += k + 1;
	temp = ft_strdup(&(toto->buf[k + 1]));
	free (toto->buf);
	toto->buf = ft_strdup(temp);
	free (temp);
	if (!ft_set_zero(toto) && !toto->buf)
		return (0);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_static toto;
	char			*tmp;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!toto.size)
	{
		tmp = malloc(BUFF_SIZE + 1);
		toto.i = read(fd, tmp, BUFF_SIZE);
		debug(tmp);
		if (toto.i)
		{	
			tmp[toto.i] = 0;
			if (!toto.size)
			{
				toto.buf = strdup(tmp);
			}
			else
			{							
				toto.buf = ft_strjoin(toto.buf, tmp);
			}
			toto.size += toto.i;	
		}
		if (toto.i < 0)
		{
			toto.buf[0] = 0;
			return (-1);
		}
		free(tmp);
	}	
	return (ft_cpy(&toto, line));
}

*/
