/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:25:26 by ekordi            #+#    #+#             */
/*   Updated: 2023/10/02 15:06:11 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "My_C_Library/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

typedef struct t_so_long
{
	int		fd;
	int		collectiblecount;
	int		playercount;
	int		exitcount;
	int		heightmap;
	int		widthmap;
	int		p_posx;
	int		p_posy;
	int		gamecount;
	char	**map;
	void	*mlx;
	void	*window;
	void	*wall;
	void	*collectable;
	void	*floor;
	void	*exit;
	void	*player;

}			t_complete;

int			read_check_map(t_complete *game, char **argv);
void		exit_validation(t_complete *game);
void		graphics(t_complete *game);
int			controller_input(int key, t_complete *game);
int			exit_point(t_complete *game);
int			check_file_type(char **argv, t_complete *game);

#endif
