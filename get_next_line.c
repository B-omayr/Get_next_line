/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:22:21 by iomayr            #+#    #+#             */
/*   Updated: 2021/12/22 18:00:15 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all_line(int fd, char *str)
{
	char	*buff;
	int		byte;

	byte = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[byte] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free (buff);
	return (str);
}

char	*get_line(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		dest[i] = str[i];
	if (str[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_rest(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dest)
		return (NULL);
	i++;
	while (str[i] != '\0')
		dest[j++] = str[i++];
	dest[j] = '\0';
	free (str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*dest;

	if (fd < 0 || (BUFFER_SIZE <= 0))
		return (NULL);
	str = get_all_line(fd, str);
	if (!str)
		return (NULL);
	dest = get_line(str);
	str = get_rest(str);
	return (dest);
}
