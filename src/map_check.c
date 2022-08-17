/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:05:20 by seheo             #+#    #+#             */
/*   Updated: 2022/08/17 16:13:17 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_check_wall(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		if (i < game->width)
		{
			if (game->map[i] != '1')
				error("wrong wall");
		}
		else if (i % game->width == 0 || i % game->width == game->width - 1)
		{
			if (game->map[i] != '1')
				error("wrong wall");
		}
		else if (i > ft_strlen(game->map) - game->width)
		{
			if (game->map[i] != '1')
				error("wrong wall");
		}
		i++;
	}
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->all_item = 0;
	game->current_item = 0;
	while (i++ < ft_strlen(game->map))
	{
		if (game->map[i] == 'E')
			num_e++;
		else if (game->map[i] == 'P')
			num_p++;
		else if (game->map[i] == 'C')
			game->all_item++;
        else if (!(game->map[i] == '1' || game->map[i] == '0' \
                || game->map[i] == '\n'))
            error("invalid map data");
	}
	if (num_e == 0)
		error("no exit");
	if (game->all_item == 0)
		error("no item");
	if (num_p != 1)
		error("no 1 player");
}

void	map_check(t_game *game)
{
    int map_size = ft_strlen(game->map);
    printf("\n%s\n", game->map);
    printf("%d", map_size);
	if (game->height * game->width != map_size)
		error("no Rectangle");
	map_check_wall(game);
	map_check_params(game);
}