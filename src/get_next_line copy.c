/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:06:34 by seheo             #+#    #+#             */
/*   Updated: 2022/09/15 21:12:49 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*next_line(char *result)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(result) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (result[i])
		s[c++] = result[i++];
	s[c] = '\0';
	free(result);
	return (s);
}

char	*get_line(char *file_text)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!file_text[i])
		return (NULL);
	while (file_text[i] && file_text[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (file_text[i] && file_text[i] != '\n')
	{
		tmp[i] = file_text[i];
		i++;
	}
	if (file_text[i] == '\n')
	{
		tmp[i] = file_text[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	int				count;
	char			buf[BUFFER_SIZE + 1];
	char			*result;
	static char		*file_text[1024];

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	while (count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (NULL);
		buf[count] = '\0';
		file_text[fd] = ft_strjoin(file_text[fd], buf);
		if (!file_text[fd])
			return (NULL);
		if (ft_strchr(file_text[fd], '\n'))
			break ;
	}
	result = get_line(file_text[fd]);
	file_text[fd] = next_line(file_text[fd]);
	return (result);
}
