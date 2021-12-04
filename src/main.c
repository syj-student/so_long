/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:27:54 by yusong            #+#    #+#             */
/*   Updated: 2021/12/04 17:37:34 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(int argc, char **argv)
{
	t_ptr	game;

	loadMap("map/map.ber", &game);

	// int x, y;
	// x = 0;
	// while (game.map[x])
	// {
	// 	y = 0;
	// 	while (game.map[x][y])
	// 	{
	// 		printf("%c", game.map[x][y]);
	// 		y++;
	// 	}
	// 	printf("\n");
	// 	x++;
	// }
	// printf("esc %ld %ld\n", game.esc_x, game.esc_y);
	// printf("esc %ld %ld\n", game.player_x, game.player_y);
	// printf("height : %ld / width : %ld %c %ld\n", game.map_height, game.map_width, game.map[0][5], game.total_c);
	game.mlx = mlx_init();
	makeImage(&game);
	printf("m check\n");
	game.win = mlx_new_window(game.mlx, game.map_height * 100,\
								game.map_width * 100, "so_long");
	mlx_loop_hook(game.mlx, printScreen, &game);
	mlx_key_hook(game.win, keyEvent, &game);
	mlx_loop(game.mlx);
}

// 키이벤트 발생시
// 1. 포지션 옮기기 (유효한 움직임 체크) : mlx_key_hook
// 2. 맵 그리그 : mlx_loop_hook (아무 입력없을 때)
// 3. 위 동작 상시 작동중이여야함.
// 4. 탈출구에 들어갈 때 C 다 먹었는지 확인
// 5. 종료 : mlx_destory_window (함수사용없이 exit() 사용가능?)

void	errorExit(char *error_msg)
{
	printf("%s Error\n", error_msg);
	exit(1);
}
