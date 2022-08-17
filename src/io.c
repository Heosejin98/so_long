/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:56:51 by seheo             #+#    #+#             */
/*   Updated: 2022/08/17 15:47:25 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == ESC)
		exit_game(game);
	if (key_code == W)
		move_w(game);
	if (key_code == A)
		move_a(game);
	if (key_code == S)
		move_s(game);
	if (key_code == D)
		move_d(game);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!(s) || fd < 0)
		return ;
	write(fd, s, ft_strlen(s) - 1);
	write(fd, "\n", 2);
}

void	error(char *str)
{
	write(2, "Error ", 6);
	ft_putstr_fd(str, 2);
	exit(1);
}