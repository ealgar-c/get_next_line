/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:41:14 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/04/28 11:36:02 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* char	*get_line(int fd)
{
	
}
*/
char	*get_next_line(int fd)
{
	static ssize_t	read_chars;
	char			*buf;

	buf = malloc(10 * sizeof(char));
	read_chars += read(fd, buf, 10);
	return (buf);
}

int	main(void)
{
	int	fd;

	fd = open("quijote.txt", O_RDONLY);
	while (fd + 1)
	{
		printf("%s", get_next_line(fd));
	}
	close(fd);
	return (0);
}
