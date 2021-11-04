/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:21:32 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 17:21:32 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

static char	mapComponentChecker(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	mapComponentCheck(char **map)
{
	char	*components;
	int		k;

	components = "10PEC\0";
	k = 0;
	while (components[k])
	{
		if (mapComponentChecker(map, components[k]))
			errorExit("Invalid map(Components)");
		k++;
	}
}

void	setPlayerPosition(char **map, t_ptr *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}