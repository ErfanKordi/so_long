/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:25:26 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/01 12:32:43 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
#include <stdbool.h>
#include "My_C_Library/libft.h"

typedef struct t_so_long
{
	int	fd;
	int	Collectible;
	int playercount;
	int exitcount;
	int heightmap;
	int	widthmap;
	int	PposX;
	int	PposY;
	int gamecount;
	char **map;
	void *mlx;
	void *window;
	void *wall;
	void *collectable;
	void *floor;
	void *exit;
	void *player;


} t_complete;

int read_check_map(t_complete *game, char **argv);
void exit_validation(t_complete *game);
void graphics(t_complete *game);
int	controller_input(int key, t_complete *game);
int	exit_point(t_complete *game);


#endif
