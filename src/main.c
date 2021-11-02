/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:27:54 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 12:25:22 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv)
{
	t_ptr	game;
	char	**map;

	loadMap("./map/map.ber", map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1920, 1080, "Hello yusong");
	mlx_loop(game.mlx);
}

void	errorExit(char *error_msg)
{
	printf("%s Error\n", error_msg);
	exit(1);
}
