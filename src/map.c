/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:50:33 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 12:21:40 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	loadMap(char *map_name, char **map)
{
	int		map_fd;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
		errorExit("Open");
	map = readLines(map_fd);
	int x;
	x = 0;
	while (map[x])
	{
		printf("%s\n", map[x]);
		x++;
	}
}

char	**readLines(int fd)
{
	char	buffer[100];
	char	*line;
	char	**lines;
	int		i;

	line = 0;
	while (read(fd, buffer, 100) > 0)
		line = combineTwoLines(line, buffer);
	if (!line || !*line)
		errorExit("Map");
	return ft_split(line, '\n');
}

static size_t	duplicateLine(char *dst, char *src, size_t start)
{
	size_t	i;

	if (!src)
		return (start);
	i = 0;
	while (src[i])
	{
		dst[start] = src[i];
		start++;
		i++;
	}
	free(src);
	return (start);
}

char	*combineTwoLines(char *l1, char *l2)
{
	size_t	i;
	char	*comb_line;

	comb_line = (char *)safeMalloc(ft_strlen(l1) + ft_strlen(l2) + 1);
	i = duplicateLine(comb_line, l1, 0);
	i = duplicateLine(comb_line, l2, i);
	comb_line[i] = '\0';
	return (comb_line);
}

size_t	ft_strlen(char *str)
{
	size_t	cnt;

	if (!str || !*str)
		return (0);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}
