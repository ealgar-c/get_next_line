/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:41:14 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/04/29 13:57:03 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_actual_line(char *acum_str)
{
	// esta funcion tiene que recibir el acum_str
	// y pasar a otro str lo que haya hasta q acabe 
	// o encuentre un \n y devolver este
}

char	*get_stoned(char *acum_str, char *tmp)
{
	char	*ret;

	ret = ft_strjoin(acum_str, tmp);
	free(acum_str);
	return (ret);
}

char	*get_buffed(int fd, char *acum_str)
{
	char	*tmp;
	int		i;

	if (acum_str = NULL)
		acum_str = ft_calloc(1, sizeof(char));
	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[i] = '\0';
		acum_str = get_stoned(acum_str, tmp);
		if (// aqui queremos una función que busque si ya hay en la temporal un \n)
			break;
	}
	free(tmp);
	return acum_str;
}

char	*get_next_line(int fd)
{
	static char	*acum_str;
	char		*act_line;

	if (fd < 1)
		return (NULL);
	acum_str = get_buffed(fd, acum_str);
	act_line = get_actual_line(acum_str);
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
