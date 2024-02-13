/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joel <joel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:39:04 by joelozan          #+#    #+#             */
/*   Updated: 2024/02/13 22:05:20 by joel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == c)
		return ((char *)str + i);
	return (0);
}

static char	*set_line(char *buff)
{
	char	*stash;
	size_t	i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == 0)
		return (NULL);
	stash = ft_substr(buff, i + 1, ft_strlen(buff) - i);
	if (!(*stash))
	{
		free(stash);
		stash = NULL;
	}
	buff[i + 1] = 0;
	return (stash);
}

static char	*add_new_line(int fd, char *stash, char *buff)
{
	int		b_read;
	char	*tmp;

	b_read = 1;
	while (b_read)
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buff[b_read] = 0;
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		free(buff);
		stash = NULL;
		buff = NULL;
		return (NULL);
	}
	line = add_new_line(fd, stash, buff);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	stash = set_line(stash);
	return (line);
}
