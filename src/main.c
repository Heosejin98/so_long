/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:48:07 by seheo             #+#    #+#             */
/*   Updated: 2022/09/15 21:58:57 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		error("no map");
	file_type_check(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	game_init(game, argv[1]);
	map_check(game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, 0, &press_key, game);
	mlx_hook(game->mlx_win, DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
