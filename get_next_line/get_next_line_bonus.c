/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:01:28 by eviscont          #+#    #+#             */
/*   Updated: 2023/12/07 12:20:44 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*concat_line(char *line, char *buffer)
{
	char	*new_line;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(line);
	len2 = 0;
	while (buffer[len2] != '\0' && buffer[len2] != '\n')
		len2++;
	if (buffer[len2] == '\n')
		len2++;
	new_line = (char *)malloc(len1 + len2 + 1);
	if (new_line == NULL)
		return (free(line), NULL);
	ft_strlcpy(new_line, line, len1);
	ft_strlcpy(new_line + len1, buffer, len2);
	new_line[len1 + len2] = '\0';
	return (free(line), new_line);
}

static void	obtain_remaining(char *buffer)
{
	size_t	i;
	size_t	res;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
	{
		res = ft_strlen(&buffer[i + 1]);
		ft_strlcpy(buffer, &buffer[i + 1], res);
		buffer[res] = '\0';
	}
	else
		buffer[0] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = concat_line(NULL, buffer[fd]);
	if (line == NULL)
		return (NULL);
	while (ft_strchr(line, '\n') == 0)
	{
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(line) == 0))
			return (buffer[fd][0] = '\0', free(line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[fd][bytes_read] = '\0';
		line = concat_line(line, buffer[fd]);
		if (line == NULL)
			return (NULL);
	}
	return (obtain_remaining(buffer[fd]), line);
}
