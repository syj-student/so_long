/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:49:41 by yusong            #+#    #+#             */
/*   Updated: 2021/11/28 15:49:41 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	keyEvent(int keycode, t_ptr *game)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		movePosition(1, -1, game);
	else if (keycode == 1)
		movePosition(1, 1, game);
	else if (keycode == 0)
		movePosition(0, -1, game);
	else if (keycode == 2)
		movePosition(0, 1, game);

}

void	movePosition(int xy, int d, t_ptr *game)
{
	size_t	dx;
	size_t	dy;

	if (xy)
	{
		dx = game->player_x;
		dy = game->player_y + d;
	}
	else
	{
		dx = game->player_x + d;
		dy = game->player_y;
	}
	if (game->map[dx][dy] == '1')
		return ;
	if (game->map[dx][dy] == 'C')
	{
		changePosition(dx, dy, game);
		game->total_c--;
	}
	else if (game->map[dx][dy] == 'E')
	{
		if (game->total_c == 0)
			exit(0);
		
	}
}

void	changePosition(size_t dx, size_t dy, t_ptr *game)
{
	game->map[game->player_x][game->player_y] = '0';
	game->player_x = dx;
	game->player_y = dy;
	game->map[dx][dy] = 'P';
}

char	positionCheckY(int dxy, t_ptr *game)
{
	if (dxy <= 0 || dxy >= game->map_width)
		return (0);
}