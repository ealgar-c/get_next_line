/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealgar-c <ealgar-c@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:41:14 by ealgar-c          #+#    #+#             */
/*   Updated: 2023/05/01 16:13:54 by ealgar-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_clean_line(char *acum_str)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	while (acum_str[i] != '\0' && acum_str[i] != '\n')
		i++;
	if (acum_str[i] == '\0')
	{
		free(acum_str);
		return (NULL);
	}
	r = ft_calloc((ft_strlen(acum_str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (acum_str[i] != '\0')
		r[j++] = acum_str[i++];
	free(acum_str);
	if (r[0] == '\0')
	{
		free(r);
		return (NULL);
	}
	return (r);
}

static char	*get_actual_line(char *acum_str)
{
	char	*r;
	int		i;

	i = 0;
	if (acum_str[i] == '\0')
		return (NULL);
	while (acum_str[i] != '\0' && acum_str[i] != '\n')
		i++;
	r = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (acum_str[i] != '\0' && acum_str[i] != '\n')
	{
		r[i] = acum_str[i];
		i++;
	}
	if (acum_str[i] != '\0' && acum_str[i] == '\n')
		r[i++] = '\n';
	return (r);
}

static char	*get_joint(char *acum_str, char *buff)
{
	char	*r;

	r = ft_strjoin(acum_str, buff);
	free(acum_str);
	return (r);
}

static char	*get_a_lot(int fd, char *acum_str)
{
	char	*buff;
	int		read_char;

	if (!acum_str)
		acum_str = ft_calloc(1, sizeof(char));
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_char = 1;
	while (read_char > 0)
	{
		read_char = read(fd, buff, BUFFER_SIZE);
		if (read_char < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_char] = '\0';
		acum_str = get_joint(acum_str, buff);
		if (ft_strchr_mod(buff, '\n'))
			break ;
	}
	free(buff);
	return (acum_str);
}

char	*get_next_line(int fd)
{
	static char	*acum_str;
	char		*r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (acum_str != NULL)
		{
			free(acum_str);
			acum_str = NULL;
		}
		return (NULL);
	}
	acum_str = get_a_lot(fd, acum_str);
	r = get_actual_line(acum_str);
	acum_str = get_clean_line(acum_str);
	return (r);
}
