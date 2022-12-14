/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:31:16 by seheo             #+#    #+#             */
/*   Updated: 2022/08/18 15:14:00 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	strlen2(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*ft_strdup_without_newline(const char *s)
{
	int		i;
	int		len;
	char	*new_s;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(new_s))
		return (NULL);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
		if (s[i] == '\n')
			break ;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strjoin_without_newline(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(strlen2(s1) + strlen2(s2) + 1);
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
		if (s1[i] == '\n')
			break ;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[strlen2(s1) + strlen2(s2)] = '\0';
	free(s1);
	return (str);
}
