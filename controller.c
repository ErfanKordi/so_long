/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 09:17:13 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/02 13:06:17 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pos(t_complete *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->p_posy = y;
		game->p_posx = x;
		game->gamecount++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->p_posy = y;
		game->p_posx = x;
		game->gamecount++;
		game->collectiblecount--;
	}
	if (game->map[y][x] == 'E')
	{
		if (game->collectiblecount)
			return (0);
		ft_printf("\nYou Won, Congrats!\n");
		exit_point(game);
	}
	return (1);
}

int	w_s_move(t_complete *game, int key)
{
	int	y;
	int	x;
	int	re;

	re = 0;
	y = game->p_posy;
	x = game->p_posx;
	if (key == 13)
	{
		y--;
		re = check_pos(game, x, y);
		if (!re)
			return (0);
		game->map[y + 1][x] = '0';
	}
	if (key == 1)
	{
		y++;
		re = check_pos(game, x, y);
		if (!re)
			return (0);
		game->map[y - 1][x] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->gamecount);
	return (1);
}

int	a_d_move(t_complete *game, int key)
{
	int	y;
	int	x;
	int	re;

	re = 0;
	y = game->p_posy;
	x = game->p_posx;
	if (key == 0)
	{
		x--;
		re = check_pos(game, x, y);
		if (!re)
			return (0);
		game->map[y][x + 1] = '0';
	}
	if (key == 2)
	{
		x++;
		re = check_pos(game, x, y);
		if (!re)
			return (0);
		game->map[y][x - 1] = '0';
	}
	ft_printf("Steps Taken: %i\n", game->gamecount);
	return (1);
}

int	controller_input(int key, t_complete *game)
{
	int	re;

	re = 0;
	if (key == 53)
		exit_point(game);
	if (key == 13)
		re = w_s_move(game, key);
	if (key == 1)
		re = w_s_move(game, key);
	if (key == 2)
		re = a_d_move(game, key);
	if (key == 0)
		re = a_d_move(game, key);
	if (re)
		graphics(game);
	return (1);
}
