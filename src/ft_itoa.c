/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:09:34 by seheo             #+#    #+#             */
/*   Updated: 2022/08/18 15:23:44 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	minus(char *output, int len, int sign)
{
	if (sign < 0)
	{
		output[0] = '-';
		len++;
	}
	return (len);
}

int	change(char *temp, int len, int n)
{
	while (n != 0)
	{
		temp[len++] = n % 10 + '0';
		n = n / 10;
	}
	temp[len] = 0;
	return (len);
}

char	*malloc_output(int *len, int sign, char *temp, int n)
{
	char	*output;

	output = 0;
	*len = change(temp, *len, n);
	if (sign < 0)
		output = (char *)ft_calloc(*len + 2, sizeof(char));
	else
		output = (char *)ft_calloc(*len + 1, sizeof(char));
	return (output);
}

char	*ft_itoa(int n)
{
	int		len;
	char	temp[11];
	char	*output;
	size_t	i;
	int		sign;

	len = 0;
	sign = 1;
	if (n == -2147483648)
		return (output = ft_strdup("-2147483648"));
	else if (n == 0)
		return (output = ft_strdup("0"));
	else if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	output = malloc_output(&len, sign, temp, n);
	if (output == 0)
		return (0);
	len = minus(output, len, sign);
	i = 0;
	while (temp[i])
		output[--len] = temp[i++];
	return (output);
}
