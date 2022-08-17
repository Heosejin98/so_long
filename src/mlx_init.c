/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:54:14 by seheo             #+#    #+#             */
/*   Updated: 2022/08/17 13:53:47 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.empty = mlx_xpm_file_to_image(mlx, "./img/empty.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &w, &h);
	img.end = mlx_xpm_file_to_image(mlx, "./img/end.xpm", &w, &h);
	img.item = mlx_xpm_file_to_image(mlx, "./img/item.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &w, &h);
	return (img);
}

void game_init(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	map_read(map, game);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "so_long"); 
	setting_img(game);
}