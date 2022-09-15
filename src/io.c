/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:56:51 by seheo             #+#    #+#             */
/*   Updated: 2022/09/15 21:58:46 by seheo            ###   ########.fr       */
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
	int	i;

	if (!(s) || fd < 0)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
	write(fd, "\n", 2);
}

void	error(char *str)
{
	write(2, "Error ", 6);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	file_type_check(char *file_name)
{
	int		i;
	int		j;
	char	ber[5];

	i = 0;
	j = 0;
	while (file_name[i] && file_name[i] != '.')
		i++;
	if (ft_strlen(file_name) - i != 4)
		error("no ber");
	while (file_name[i])
	{
		ber[j] = file_name[i];
		j++;
		i++;
	}
	if (ft_strcmp(ber, ".ber") != 0)
		error("no ber");
}
