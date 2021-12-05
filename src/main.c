/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:27:54 by yusong            #+#    #+#             */
/*   Updated: 2021/12/05 17:05:00 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv)
{
	t_ptr	game;

	loadMap("map/map.ber", &game);
	game.mlx = mlx_init();
	makeImage(&game);
	game.win = mlx_new_window(game.mlx, game.map_height * 100,\
								game.map_width * 100, "so_long");
	mlx_loop_hook(game.mlx, printScreen, &game);
	mlx_key_hook(game.win, keyEvent, &game);
	mlx_loop(game.mlx);
}

void	makeImage(t_ptr *game)
{
	int	x;

	game->img[0] = mlx_png_file_to_image(game->mlx, "img/wall.png", &x, &x);
	game->img[1] = mlx_png_file_to_image(game->mlx, "img/player.png", &x, &x);
	game->img[2] = mlx_png_file_to_image(game->mlx, "img/food.png", &x, &x);
	game->img[3] = mlx_png_file_to_image(game->mlx, "img/exit.png", &x, &x);
	game->event_flag = 1;
}

void	errorExit(char *error_msg)
{
	printf("%s Error\n", error_msg);
	exit(1);
}
