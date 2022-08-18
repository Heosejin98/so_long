/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_walk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:10:59 by seheo             #+#    #+#             */
/*   Updated: 2022/08/18 15:25:02 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	printf_walk(int n)
{
	char	*walk;

	walk = ft_itoa(n);
	ft_putstr_fd(walk, 1);
	free(walk);
}