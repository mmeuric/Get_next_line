/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:22:56 by mmeuric          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:55 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isnewline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_and_keep(int fd, char *stock)
{
	char	*buff;
	int		lecture;
	int		check;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	lecture = 1;
	check = 0;
	while (lecture > 0 && check == 0)
	{
		lecture = read(fd, buff, BUFFER_SIZE);
		if (lecture == -1)
			return (free(buff), free(stock), NULL);
		buff[lecture] = '\0';
		check = ft_isnewline(buff);
		stock = ft_strjoin(stock, buff);
		if (!stock)
			return (free(buff), NULL);
	}
	free(buff);
	return (stock);
}

char	*ft_extract_line(char *stock)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (stock[len] != '\n' && stock[len] != '\0')
		len++;
	if (stock[len] == '\0')
	{
		if (!len)
			return (NULL);
		return (ft_strdup(stock));
	}
	len++;
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (++i < len)
		line[i] = stock[i];
	line[i] = '\0';
	return (line);
}

char	*ft_clean(char *stock)
{
	int		i;
	int		x;
	char	*tmp;

	i = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (stock[i] == '\0')
		return (free(stock), NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	x = 0;
	while (stock[i])
		tmp[x++] = stock[i++];
	tmp[x] = '\0';
	return (free(stock), tmp);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stock)
		stock = ft_strdup("");
	line = NULL;
	stock = ft_read_and_keep(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_extract_line(stock);
	stock = ft_clean(stock);
	return (line);
}
