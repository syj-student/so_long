/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:57:31 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 12:07:32 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

void	mapChecker(char **map, t_ptr *game)
{
	checkRectangleAndValidChar(map, game);
	checkSurroundWall(map, game);
}

static char	isWall(char c)
{
	if (c == '1')
		return (0);
	return (1);
}

void	checkSurroundWall(char **map, t_ptr *game)
{
	size_t	width;
	size_t	height;

	width = 0;
	height = 0;
	while (width < game->map_width)
	{
		map[0]
		width++;
	}
	while (height < game->map_height)
	{
		height++;
	}

}

static char	isValidCharacter(char c)
{
	char	*valid_char;
	int		i;

	valid_char = "10PEC\0";
	i = 0;
	while (valid_char[i])
	{
		if (valid_char[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	checkRectangleAndValidChar(char **map, t_ptr *game)
{
	size_t	width;
	size_t	height;
	size_t	pre_width;

	pre_width = 0;
	height = 0;
	while (map[height])
	{
		width = 0;
		while (map[height][width])
		{
			if (isValidCharacter(map[height][width]))
				errorExit("Invalid map");
			width++;
		}
		if (pre_width)
			if (pre_width - width)
				errorExit("Map Rectangle")
		pre_width = width;
		height++;
	}
	game->map_width = width;
	game->map_height = height;
}