/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:50:33 by yusong            #+#    #+#             */
/*   Updated: 2021/11/04 09:19:38 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	loadMap(char *map_name, char ***map1, t_ptr *game)
{
	int		map_fd;
	char	**map;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
		errorExit("Open");
	map = readLines(map_fd);
	mapChecker(map, game);
	setPlayerPosition(map, game);
	*map1 = map;
}

char	**readLines(int fd)
{
	char	buffer[100];
	char	*line;
	char	**lines;
	int		i;
	int		cnt;

	line = (char *)safeMalloc(1);
	line[0] = 0;
	cnt = read(fd, buffer, 100);
	while (cnt > 0)
	{
		buffer[cnt] = '\0';
		line = combineTwoLines(line, buffer);
		cnt = read(fd, buffer, 100);
	}
	if (!line || !*line)
		errorExit("Map");
	lines = ft_split(line, '\n');
	free(line);
	return (lines);
}

static size_t	duplicateLine(char *dst, char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[start] = src[i];
		start++;
		i++;
	}
	return (start);
}

char	*combineTwoLines(char *l1, char *l2)
{
	size_t	i;
	char	*comb_line;

	comb_line = (char *)safeMalloc(ft_strlen(l1) + ft_strlen(l2) + 1);
	i = duplicateLine(comb_line, l1, 0);
	i = duplicateLine(comb_line, l2, i);
	free(l1);
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
