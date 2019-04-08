/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndanilov <ndanilov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 23:10:09 by ndanilov          #+#    #+#             */
/*   Updated: 2018/12/30 18:24:03 by biswbara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_thread_into_line(char **thread, char **line, int fd, int len)
{
	int		i;
	char	*tmp;

	i = 0;
	while (thread[fd][i] != '\n' && thread[fd][i] != '\0')
		i++;
	if (thread[fd][i] == '\n')
	{
		*line = ft_strsub(thread[fd], 0, i);
		tmp = ft_strdup(thread[fd] + i + 1);
		free(thread[fd]);
		thread[fd] = tmp;
		if (thread[fd][0] == '\0')
			ft_strdel(&thread[fd]);
	}
	else if (thread[fd][i] == '\0')
	{
		if (len == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(thread[fd]);
		ft_strdel(&thread[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		*tmp;
	ssize_t		read_bytes;
	static char *thread[MAX_FD];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || fd > MAX_FD || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	while ((read_bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_bytes] = '\0';
		if (thread[fd] == NULL)
			thread[fd] = ft_strnew(0);
		tmp = ft_strjoin(thread[fd], buf);
		free(thread[fd]);
		thread[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	else if (read_bytes == 0 && (thread[fd] == NULL || thread[fd][0] == '\0'))
		return (0);
	return (read_thread_into_line(thread, line, fd, read_bytes));
}
