/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:16:51 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/02 12:47:06 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_complete *game, int *n_ptr, int *line_ptr)
{
	int	n;
	int	line;

	n = 0;
	line = 0;
	while (game->map[line])
	{
		while (game->map[line][n])
		{
			if (game->map[line][n] == 'P')
			{
				*n_ptr = n;
				*line_ptr = line;
				return ;
			}
			else
				n++;
		}
		n = 0;
		line++;
	}
}

void	floodfillutil(t_complete *game, int x, int y, int visited[100][100])
{
	int	dx[4];
	int	dy[4];
	int	new_x;
	int	new_y;
	int	i;

	i = 0;
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
	visited[y][x] = 1;
	while (i < 4)
	{
		new_x = x + dx[i];
		new_y = y + dy[i++];
		if (new_x >= 0 && new_x < game->widthmap && new_y >= 0
			&& new_y < game->heightmap && game->map[new_y][new_x] != '1'
			&& !visited[new_y][new_x])
			floodfillutil(game, new_x, new_y, visited);
	}
}

int	ispathexists(t_complete *game, int visited[100][100])
{
	int	start_x;
	int	start_y;
	int	i;
	int	j;

	start_x = -1;
	start_y = -1;
	player_position(game, &start_x, &start_y);
	floodfillutil(game, start_x, start_y, visited);
	i = 0;
	while (i < game->heightmap)
	{
		j = 0;
		while (j < game->widthmap)
		{
			if (game->map[i][j] == 'E' && visited[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	exit_validation(t_complete *game)
{
	int	visited[100][100];
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	if (!ispathexists(game, visited))
	{
		ft_printf("path doesnt exits");
		exit(1);
	}
}
