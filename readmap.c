/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:33:16 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/01 12:49:24 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	readmap(t_complete *game, char **argv)
{
	char	*line;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while ((line = get_next_line(game->fd)) != NULL)
	{
		game->map = realloc(game->map, sizeof(char *) * (game->heightmap + 1));
		if (!game->map)
		{
			close(game->fd);
			return (0);
		}
		game->map[game->heightmap] = line;
		if (game->heightmap == 0)
			game->widthmap = ft_strlen(line) - 1;
		game->heightmap++;
	}
	close(game->fd);
	return (1);
}
int	map_parsing(t_complete *game)
{
	int	line;
	int	n;

	line = 0;
	while (line < game->heightmap)
	{
		n = 0;
		while (n < game->widthmap)
		{
			if (!strchr("10PCE\n", game->map[line][n]))
			{
				printf("error at line %d and coulumn %d\n", line + 1, n + 1);
				exit_point(game);
			}
			if (game->map[line][n] == 'P')
				game->playercount++;
			else if (game->map[line][n] == 'C')
				game->Collectible++;
			else if (game->map[line][n] == 'E')
				game->exitcount++;
			n++;
		}
		line++;
	}
	return (1);
}
int	wall_check(t_complete *game)
{
	int	line;
	int	n;

	n = 0;
	line = 1;
	while (strchr("1", game->map[0][n]) && strchr("1", game->map[game->heightmap
			- 1][n]) && n < game->widthmap)
		n++;
	while (line < game->heightmap && strchr("1", game->map[line][0])
		&& strchr("1", game->map[line][game->widthmap - 1]))
		line++;
	if (line != game->heightmap || n != game->widthmap)
	{
		printf("Surround walls error");
		exit_point(game);
	}
	return (1);
}
int	character_check(t_complete *game)
{
	if (!(game->playercount == 1 && game->Collectible >= 1
			&& game->exitcount == 1))
	{
		printf("Invalid map, either player, exit or collectable count\n");
		exit_point(game);
	}
	return (0);
}
int	read_check_map(t_complete *game, char **argv)
{
	readmap(game, argv);
	map_parsing(game);
	wall_check(game);
	character_check(game);
	return (1);
}
