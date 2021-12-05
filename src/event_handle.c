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
	return (1);
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
	else if (game->map[dx][dy] == 'E' && game->total_c == 0)
		exit(0);
	else if (game->map[dx][dy] == '0')
		changePosition(dx, dy, game);
	game->event_flag = 1;
}

void	changePosition(size_t dx, size_t dy, t_ptr *game)
{
	game->map[game->player_x][game->player_y] = '0';
	game->player_x = dx;
	game->player_y = dy;
	game->map[dx][dy] = 'P';
}

static void	printImg(size_t x, size_t y, t_ptr *game)
{
	if (game->map[x][y] == '1')
		mlx_put_image_to_window \
		(game->mlx, game->win, game->img[0], 100 * x, 100 * y);
	else if (game->map[x][y] == 'P')
		mlx_put_image_to_window \
		(game->mlx, game->win, game->img[1], 100 * x, 100 * y);
	else if (game->map[x][y] == 'C')
		mlx_put_image_to_window \
		(game->mlx, game->win, game->img[2], 100 * x, 100 * y);
	else if (game->map[x][y] == 'E')
		mlx_put_image_to_window \
		(game->mlx, game->win, game->img[3], 100 * x, 100 * y);
}

int	printScreen(t_ptr *game)
{
	size_t	x;
	size_t	y;

	if (game->event_flag == 1)
	{
		mlx_clear_window(game->mlx, game->win);
		x = 0;
		while (x < game->map_height)
		{
			y = 0;
			while (y < game->map_width)
			{
				printImg(x, y, game);
				y++;
			}
			x++;
		}
		game->event_flag = 0;
	}
	return (1);
}
