/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:15:32 by iomayr            #+#    #+#             */
/*   Updated: 2021/12/22 16:17:57 by iomayr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*dest;
	int		i;
	int		j;

	j = -1;
	i = -1;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!buff)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff) + 1));
	if (!dest)
		return (NULL);
	while (str[++i] != '\0')
		dest[i] = str[i];
	while (buff[++j] != '\0')
		dest[i + j] = buff[j];
	dest[i + j] = '\0';
	free (str);
	return (dest);
}

char	*ft_strchr(char *buff, int c)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == (char)c)
			return (&buff[i]);
		i++;
	}
	if (buff[i] == (char)c)
		return (&buff[i]);
	return (0);
}
