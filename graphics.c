/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:25:59 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/01 11:54:59 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_complete *game, void *img_type, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img_type, x * 60, y * 60);
}
static void	game_images(t_complete *game)
{
	int	i;
	int	j;

	game->player = mlx_xpm_file_to_image(game->mlx, "game_images/player.xpm",
		&i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlx, "game_images/floor.xpm", &i,
		&j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "game_images/wall.xpm", &i,
		&j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "game_images/exit.xpm", &i,
		&j);
	game->collectable = mlx_xpm_file_to_image(game->mlx, "game_images/item.xpm",
		&i, &j);
	}
void	which_img(t_complete *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		put_image(game, game->player, x, y);
		game->PposY = y;
		game->PposX = x;
	}
	else if (game->map[y][x] == '1')
		put_image(game, game->wall, x, y);
	else if (game->map[y][x] == 'E')
		put_image(game, game->exit, x, y);
	else if (game->map[y][x] == 'C')
		put_image(game, game->collectable, x, y);
}
static void	takeimage(t_complete *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->heightmap)
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image(game, game->floor, x, y);
			which_img(game, x, y);
			x++;
		}
		y++;
	}
}
void	graphics(t_complete *game)
{
	game_images(game);
	takeimage(game);
}
