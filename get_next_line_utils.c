/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:47 by mmeuric           #+#    #+#             */
/*   Updated: 2024/11/25 17:55:17 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(str);
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (dest);
	else
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strjoin(char *stock, char *buff)
{
	size_t	size;
	char	*join;
	int		i;
	int		x;

	x = 0;
	i = 0;
	size = ft_strlen(stock) + ft_strlen(buff);
	join = (char *)malloc(size + 1);
	if (!join)
		return (free(stock), NULL);
	while (stock[i])
	{
		join[i] = stock[i];
		i++;
	}
	while (buff[x])
	{
		join[i + x] = buff[x];
		x++;
	}
	join[i + x] = '\0';
	return (free(stock), join);
}
