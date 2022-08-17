/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:54:14 by seheo             #+#    #+#             */
/*   Updated: 2022/08/16 22:05:44 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img img_init()
{
    t_img img;

    img.empty = 
}

t_game game_init()
{
    t_game game;

    game = (t_game *)malloc(sizeof(t_game));
    game->height = 0;
    game->width = 0;
    game->img = img_init();
    game

}