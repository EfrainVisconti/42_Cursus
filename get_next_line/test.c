/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:54:44 by eviscont          #+#    #+#             */
/*   Updated: 2023/11/29 16:43:24 by eviscont         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	size;
	char	*d;

	i = 0;
	size = ft_strlen((char *)s) + 1;
	d = (char *)malloc(size);
	if (d == 0)
		return (free(d), NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char			*res;
// 	unsigned int	i;
// 	unsigned int	j;

// 	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	i = 0;
// 	j = 0;
// 	if (res == NULL)
// 		return (0);
// 	while (i < ft_strlen(s1))
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }

void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = 0;
	while (s2[len2] != '\0' && s2[len2] != '\n')
		len2++;
	if (s2[len2] == '\n')
		len2++;
	res = (char *)malloc(len1 + len2 + 1);
	if (res == NULL)
		return (free(res), NULL);
	ft_strlcpy(res, s1, len1);
	ft_strlcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sb;
	unsigned int	i;

	i = 0;
	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sb = (char *)malloc(len + 1);
	if (sb == 0)
		return (0);
	while (i < len)
	{
		sb[i] = s[start];
		start++;
		i++;
	}
	sb[i] = '\0';
	return (sb);
}

char	*extract_line(char *basin_buffer)
{
	int		i;
	char	*new_line;

	i = 0;
	while (basin_buffer[i] != '\n' && basin_buffer[i] != '\0')
		i++;
	if (basin_buffer[i] == 0)
		return (0);
	new_line = ft_substr(basin_buffer, 0, i + 1);
	if (*new_line == 0)
	{
		free(new_line);
		new_line = NULL;
	}
	return (new_line);
}

char	*obtain_remaining(char *basin_buffer)
{
	int		i;
	char	*rest;

	i = 0;
	while (basin_buffer[i] != '\n' && basin_buffer[i] != '\0')
		i++;
	if (basin_buffer[i] == 0)
		return (0);
	rest = ft_substr(basin_buffer, i + 1, ft_strlen(basin_buffer) - i);
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	basin_buffer[i + 1] = 0;
	return (rest);
}

char *append_buffer(char *basin_buffer, char *read_buffer)
{
	char *temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

static char	*read_from_file(char *basin_buffer, int fd)
{
	int			bytes_read;
	char		*cup_buffer;

	cup_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(cup_buffer), NULL);
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char		*basin_buffer;
	char			*line;

	if (fd < 0 || read(fd,NULL,0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer)
		basin_buffer = (char *)malloc(1);
	if (!ft_strchr(basin_buffer, '\n'))
		basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (free (basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
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
		printf("[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
}
