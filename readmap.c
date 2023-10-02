/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:33:16 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/02 15:07:01 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	readmap(t_complete *game)
{
	char	*line;

	line = get_next_line(game->fd);
	if (!line)
	{
		ft_putstr_fd("empty map file", 2);
		exit(1);
	}
	while (line != NULL)
	{
		game->map = realloc(game->map, sizeof(char *) * (game->heightmap + 1));
		if (!game->map)
		{
			close(game->fd);
			free(line);
			exit(1);
		}
		game->map[game->heightmap] = line;
		if (game->heightmap == 0)
			game->widthmap = ft_strlen(line) - 1;
		game->heightmap++;
		line = get_next_line(game->fd);
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
				ft_printf("error at line %d and coulumn %d\n", line + 1, n + 1);
				exit_point(game);
			}
			if (game->map[line][n] == 'P')
				game->playercount++;
			else if (game->map[line][n] == 'C')
				game->collectiblecount++;
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
		ft_printf("Surround walls error");
		exit_point(game);
	}
	return (1);
}

int	character_check(t_complete *game)
{
	if (!(game->playercount == 1 && game->collectiblecount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("Invalid map, either player, exit or collectable count\n");
		exit_point(game);
	}
	return (0);
}

int	read_check_map(t_complete *game, char **argv)
{
	check_file_type(argv, game);
	readmap(game);
	map_parsing(game);
	wall_check(game);
	character_check(game);
	return (1);
}
