/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:27:54 by yusong            #+#    #+#             */
/*   Updated: 2021/12/07 18:05:56 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv)
{
	t_ptr	game;

	if (argc != 2)
		errorExit("MapInput");
	loadMap(argv[1], &game);
	game.mlx = mlx_init();
	makeImage(&game);
	game.win = mlx_new_window(game.mlx, game.map_width * 100, \
								game.map_height * 100, "so_long");
	mlx_loop_hook(game.mlx, printScreen, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_key_hook(game.win, keyEvent, &game);
	mlx_loop(game.mlx);
}

int	ft_close(t_ptr *game)
{
	size_t	i;

	i = 0;
	while (i < game->map_height)
		free(game->map[i]);
	free(game->map);
	exit(0);
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
