/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:41:04 by seheo             #+#    #+#             */
/*   Updated: 2022/09/16 15:33:55 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_img(t_game *g, int w, int h)
{
	if (g->map[h * g->width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.wall, \
			w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.item, \
			w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.player, \
			w * 64, h * 64);
	else if (g->map[h * g->width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.end, \
			w * 64, h * 64);
	else
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.empty, \
			w * 64, h * 64);
}

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("no search file");
	line = get_next_line(fd);
	game->height = 0;
	game->width = strlen2(line);
	game->map = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			if (game->width != strlen2(line))
				error("no Rectangle");
			game->map = ft_strjoin_without_newline(game->map, line);
		}
		free(line);
	}
	close(fd);
}

void	setting_img(t_game *game)
{
	int		current_h;
	int		current_w;

	current_h = 0;
	while (current_h < game->height)
	{
		current_w = 0;
		while (current_w < game->width)
		{
			put_img(game, current_w, current_h);
			current_w++;
		}
		current_h++;
	}
}
