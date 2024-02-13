/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joelozan <joelozan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:38:56 by joelozan          #+#    #+#             */
/*   Updated: 2024/02/13 21:38:56 by joelozan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strdup(const char *s1)
{
	char		*s2;

	s2 = (char *)malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (start <= ft_strlen(s))
	{
		if (ft_strlen(s) - start < len)
			len = ft_strlen(s) - start;
		substr = (char *)malloc((len + 1) * sizeof(char));
		if (substr == NULL)
			return (0);
		while (i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
	}
	else
	{
		substr = (char *)malloc(1 * sizeof(char));
		if (substr == NULL)
			return (0);
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;
	size_t	j;

	strjoin = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (strjoin == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		strjoin[i + j] = s2[j];
		j++;
	}
	strjoin[i + j] = '\0';
	return (strjoin);
}

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
