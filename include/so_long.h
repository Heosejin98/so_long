/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:08:27 by seheo             #+#    #+#             */
/*   Updated: 2022/08/18 15:31:27 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H  

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define ON_KEYDOWN		2
# define DESTROY_NOTIFY	17
# define BUFFER_SIZE	100

enum e_key_type
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2
};

typedef struct s_img
{
	void	*empty;
	void	*end;
	void	*item;
	void	*player;
	void	*wall;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	char	*map;
	t_img	img;
	int		walk_cnt;
	int		current_item;
	int		all_item;
}			t_game;

char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t count, size_t size);

/*
	io
*/
void	error(char *str);
int		press_key(int key_code, t_game *game);
int		exit_game(t_game *game);
void	ft_putstr_fd(char *s, int fd);

/*
	map
*/
void	map_read(char *filename, t_game *game);
void	setting_img(t_game *game);
void	map_check(t_game *game);

/*
	mlx
*/
void	game_init(t_game *game, char *map);
t_img	img_init(void *mlx);

/*
	move
*/
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_w(t_game *game);
int		clear_game(t_game *game);

/*
	gnl
*/
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*s1_init(char *s1);
int		ft_strlen(const char *str);

/*
	ft_str
*/
char	*ft_strjoin_without_newline(char *s1, char *s2);
char	*ft_strdup_without_newline(const char *s);
int		strlen2(const char *str);

void	printf_walk(int n);

#endif