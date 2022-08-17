/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:07 by seheo             #+#    #+#             */
/*   Updated: 2022/08/17 15:41:06 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	t_game	*asd;

	asd = (t_game *)malloc(sizeof(t_game));
	
	if (argc != 2)
		error("no map");
	game = (t_game *)malloc(sizeof(t_game));	
	game_init(game ,argv[1]);
	printf("%d", game->all_item);
	map_check(game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, 0, &press_key, game);
	mlx_hook(game->mlx_win, ON_KEYUP, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}         