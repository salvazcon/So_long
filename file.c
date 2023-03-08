/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:07:13 by saazcon-          #+#    #+#             */
/*   Updated: 2023/03/06 22:13:34 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ext(struct s_data *d, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'b' \
	|| file[i - 2] != 'e' || file[i - 1] != 'r')
	{
		write(1, "ERROR\n -> Extension incorrecta\n", 31);
		ft_free(d);
	}
}

char	*ft_read_file(int fd, char *line)
{
	int		readed;
	char	*buffer;

	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read (fd, buffer, 1);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = ft_calloc(sizeof(char), 1);
	line = ft_read_file(fd, line);
	return (line);
}

void	ft_check_file(struct s_data *d, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->map = get_next_line(fd);
	close(fd);
}
