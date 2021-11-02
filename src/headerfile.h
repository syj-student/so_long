/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:28:11 by yusong            #+#    #+#             */
/*   Updated: 2021/11/02 12:23:54 by yusong           ###   ########.fr       */
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
	size_t	map_width;
	size_t	map_height;
	
}				t_ptr;

//	main.c	/ 0
void	errorExit(char *error_msg);

//	map.c	/ full / static 1
void	loadMap(char *map_name, char **map);
char	**readLines(int fd);
char	*combineTwoLines(char *l1, char *l2);
size_t	ft_strlen(char *str);

//	map_checker.c	/  / static 0

//	ft_split.c	/ 4 / static 1
void	*safeMalloc(int malloc_size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	**ft_split(char *s, char c);

#endif