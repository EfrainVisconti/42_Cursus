/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:54:44 by eviscont          #+#    #+#             */
/*   Updated: 2023/12/04 16:49:44 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	size;
	char	*d;

	i = 0;
	size = ft_strlen(s) + 1;
	d = (char *)malloc(size);
	if (d == NULL)
		return (free(d), NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char *s1,char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (res == NULL)
		return (free(res), NULL);
	ft_strlcpy(res, s1, len1);
	ft_strlcpy(res, s2, len2);
	res[len1 + len2] = '\0';
	return (free(s1), res);
}

char	*ft_strchr(const char *str, int c)
{
	char	d;
	char	*nstr;

	d = (char)c;
	nstr = (char *)str;
	while (*nstr != '\0' && *nstr != d)
		nstr++;
	if (*nstr == d)
		return (nstr);
	return (0);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*sb;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sb = (char *)malloc(len + 1);
	if (sb == NULL)
		return (free(sb), NULL);
	while (i < len)
	{
		sb[i] = s[start];
		start++;
		i++;
	}
	sb[i] = '\0';
	return (sb);
}

char	*extract_line(char *line_buffer)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (0);
	new_line = ft_substr(line_buffer, 0, i + 1);
	if (*new_line == 0)
	{
		free(new_line);
		new_line = NULL;
	}
	return (new_line);
}

char	*obtain_remaining(char *line_buffer)
{
	int		i;
	char	*res;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (0);
	res = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*res == 0)
	{
		free(res);
		res = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (res);
}

char *append_buffer(char *line_buffer, char *read_buffer)
{
	char *temp;

	temp = ft_strjoin(line_buffer, read_buffer);
	return (temp);
}

static char	*read_from_file(char *line_buffer, int fd)
{
	int			bytes_read;
	char		*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		line_buffer = append_buffer(line_buffer, buffer);
		if (ft_strchr(line_buffer, '\n'))
			break ;
	}
	free (buffer);
	return (line_buffer);
}

char	*get_next_line(int fd)
{
	static char		*line_buffer;
	char			*line;

	if (fd < 0 || read(fd,NULL,0) < 0 || BUFFER_SIZE <= 0)
	{
		free(line_buffer);
		return (NULL);
	}
	if (!line_buffer)
		line_buffer = (char *)malloc(1);
	if (line_buffer == NULL)
		return (free (line_buffer), NULL);
	if (ft_strchr(line_buffer, '\n') == 0)
		line_buffer = read_from_file(line_buffer, fd);
	line = extract_line(line_buffer);
	line_buffer = obtain_remaining(line_buffer);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		printf("[%d]:%s", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
