/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:27:54 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 18:35:06 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv)
{
	t_ptr	game;
	char	**map;

	loadMap("../map/map.ber", map, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map_width * 100,\
								game.map_height * 100, "so_long");
}

// 키이벤트 발생시
// 1. 포지션 옮기기 (유효한 움직임 체크)
// 2. 맵 그리그
// 3. 위 동작 상시 작동중이여야함.
// 4. 탈출구에 들어갈 때 C 다 먹었는지 확인

int	movePosition(char **map, t_ptr *game)
{
	
}

void	errorExit(char *error_msg)
{
	printf("%s Error\n", error_msg);
	exit(1);
}
