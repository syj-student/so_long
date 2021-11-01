/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:27:54 by yusong            #+#    #+#             */
/*   Updated: 2021/11/01 14:52:18 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile.h"

int	main(void)
{
	t_ptr	b_ptr;
	void	*img_ptr;
	int w;
	int h;

	b_ptr.mlx_ptr = mlx_init();
	b_ptr.win_ptr = mlx_new_window(b_ptr.mlx_ptr, 1920, 1080, "Hello yusong");
	img_ptr = mlx_png_file_to_image(b_ptr.mlx_ptr, "testimg.png", &w, &h);
	mlx_put_image_to_window(b_ptr.mlx_ptr, b_ptr.win_ptr, img_ptr, 50, 50);
	mlx_loop(b_ptr.mlx_ptr);
}