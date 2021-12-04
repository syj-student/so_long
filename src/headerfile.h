/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:28:11 by yusong            #+#    #+#             */
/*   Updated: 2021/12/04 17:01:40 by yusong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERFILE_H
# define HEADERFILE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	char	**map;
	char	event_flag;
	size_t	map_width;
	size_t	map_height;
	size_t	player_x;
	size_t	player_y;
	size_t	esc_x;
	size_t	esc_y;
	size_t	total_c;
	void	*img[5];
}				t_ptr;

//	main.c	/
void	errorExit(char *error_msg);

//	map.c	/ full / static 1
void	loadMap(char *map_name, t_ptr *game);
char	**readLines(int fd);
char	*combineTwoLines(char *l1, char *l2);
size_t	ft_strlen(char *str);

//	map_checker.c	/ full / static 2
void	mapChecker(char **map, t_ptr *game);
void	checkSurroundWall(char **map, t_ptr *game);
void	checkRectangleAndValidChar(char **map, t_ptr *game);

//	map_checker2.c	/ 4 / static 2
void	mapComponentCheck(char **map);
void	setPlayerPosition(char **map, t_ptr *game);

//	ft_split.c	/ 4 / static 1
void	*safeMalloc(int malloc_size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	**ft_split(char *s, char c);

// event_handle.c / 
int		keyEvent(int keycode, t_ptr *game);
void	movePosition(int xy, int d, t_ptr *game);
void	changePosition(size_t dx, size_t dy, t_ptr *game);
void	makeImage(t_ptr *game);
int		printScreen(t_ptr *game);
#endif