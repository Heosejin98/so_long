/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:56:51 by seheo             #+#    #+#             */
/*   Updated: 2022/08/16 21:53:32 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_read(char *filename, t_game *game)
{
	int  fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->str = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			game->str = ft_strjoin_without_newline(game->str, line);
		}
	}
	close(fd);
	printf("%s\n", game->str);
}
