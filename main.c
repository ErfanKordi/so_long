/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:11:17 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/01 12:43:41 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mlx_image(t_complete *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->collectable)
		mlx_destroy_image(game->mlx, game->collectable);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	while (line < game->heightmap)
		free(game->map[line++]);
	free(game->map);
	destroy_mlx_image(game);
	free(game->mlx);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	read_check_map(&game, argv);
	exit_validation(&game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, (game.widthmap * 60), (game.heightmap
			* 60), "so_long");
	graphics(&game);
	mlx_key_hook(game.window, controller_input, &game);
	mlx_hook(game.window, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
	return (0);
}
