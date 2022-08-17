/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:08:27 by seheo             #+#    #+#             */
/*   Updated: 2022/08/16 22:02:46 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	SO_LONG_H
# define 	SO_LONG_H  

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//지워!!
#include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define BUFFER_SIZE				100

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img
{
	void	*empty;
	void	*end;
	void	*item;
	void	*player;
	void	*wall;
}	t_img;

typedef struct s_game{
	int		height;
	int		width;
	char	*map;
	t_img	img;
	void	*mlx;
	void	*mlx_win;
	int		walk_cnt;
}			t_game;

void	map_read(char *filename, t_game *game);


char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*s1_init(char *s1);

char	*ft_strjoin_without_newline(char *s1, char *s2);
char    *ft_strdup_without_newline(const char *s);


#endif