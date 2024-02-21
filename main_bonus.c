/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joelozan <joelozan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:03:24 by joelozan          #+#    #+#             */
/*   Updated: 2024/02/21 11:37:48 by joelozan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd1);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);

		line = get_next_line(fd2);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
}
