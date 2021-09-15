/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristi <alcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 07:54:08 by alcristi          #+#    #+#             */
/*   Updated: 2021/09/15 07:54:09 by alcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

static void	ft_strcpy(char *dest, const char *src, size_t size_src)
{
	size_t	i;
	size_t	size_dest;

	if (!dest && !src)
		return ;
	i = 0;
	size_dest = 0;
	while (dest[size_dest])
		size_dest++;
	ft_bzero(dest, size_dest);
	while (i < size_src)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static void	get_line(char **buffer, char **line, char *data)
{
	int		i;
	int		size_data;
	char	*tmp_data;

	i = 0;
	size_data = 0;
	tmp_data = ft_strdup("");
	while (buffer[0][i] != '\n' && buffer[0][i] != '\0')
		i++;
	if (buffer[0][i] == '\n')
	{
		line[0] = ft_substr(buffer[0], 0, i + 1);
		free(tmp_data);
		tmp_data = ft_strdup(&buffer[0][i + 1]);
	}
	else
		line[0] = ft_strdup(buffer[0]);
	while (tmp_data[size_data])
		size_data++;
	ft_strcpy(data, tmp_data, size_data);
	free(tmp_data);
}

static char	*ft_read(char *data, char **buffer, int fd)
{
	char	*line;
	int		r;
	int		total_r;

	r = 1;
	total_r = 0;
	while (buffer[0][total_r])
		total_r++;
	while (!ft_strchr(buffer[0], '\n') && r)
	{
		r = read(fd, data, BUFFER_SIZE);
		total_r += r;
		if (r <= 0)
			break ;
		buffer[0] = ft_strjoin(buffer[0], data);
		buffer[0][total_r] = '\0';
	}
	if (r < 0)
		return (NULL);
	else if (r == 0 && total_r == 0)
		return (NULL);
	get_line(buffer, &line, data);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	data[255][BUFFER_SIZE + 1];
	char		*line;
	char		*buffer;

	if (fd < 0 || fd > 255 || BUFFER_SIZE < 0)
		return (0);
	if (!data[fd][0])
		buffer = ft_strdup("");
	else
		buffer = ft_strdup(data[fd]);
	line = ft_read(data[fd], &buffer, fd);
	free(buffer);
	return (line);
}
