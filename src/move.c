/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:48:57 by seheo             #+#    #+#             */
/*   Updated: 2022/08/18 15:34:08 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	clear_game(t_game *game)
{
	char	*walk;

	game->walk_cnt++;
	walk = ft_itoa(game->walk_cnt);
	write(1, "END ", 5);
	ft_putstr_fd(walk, 1);
	free(walk);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < strlen2(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i - g->width] == 'C')
		g->current_item++;
	if (g->map[i - g->width] == 'E' && g->all_item == g->current_item)
		clear_game(g);
	else if (g->map[i - g->width] != '1' && g->map[i - g->width] != 'E')
	{
		g->map[i] = '0';
		g->map[i - g->width] = 'P';
		g->walk_cnt++;
		printf_walk(g->walk_cnt);
		setting_img(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < strlen2(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i - 1] == 'C')
		g->current_item++;
	if (g->map[i - 1] == 'E' && g->all_item == g->current_item)
		clear_game(g);
	else if (g->map[i - 1] != '1' && g->map[i - 1] != 'E')
	{
		g->map[i] = '0';
		g->map[i - 1] = 'P';
		g->walk_cnt++;
		printf_walk(g->walk_cnt);
		setting_img(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < strlen2(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i + g->width] == 'C')
		g->current_item++;
	if (g->map[i + g->width] == 'E' && g->all_item == g->current_item)
		clear_game(g);
	else if (g->map[i + g->width] != '1' && g->map[i + g->width] != 'E')
	{
		g->map[i] = '0';
		g->map[i + g->width] = 'P';
		g->walk_cnt++;
		printf_walk(g->walk_cnt);
		setting_img(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < strlen2(g->map))
	{
		if (g->map[i] == 'P')
			break ;
	}
	if (g->map[i + 1] == 'C')
		g->current_item++;
	if (g->map[i + 1] == 'E' && g->all_item == g->current_item)
		clear_game(g);
	else if (g->map[i + 1] != '1' && g->map[i + 1] != 'E')
	{
		g->map[i] = '0';
		g->map[i + 1] = 'P';
		g->walk_cnt++;
		printf_walk(g->walk_cnt);
		setting_img(g);
	}
}
