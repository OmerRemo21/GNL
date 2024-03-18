/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osobol <osobol@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 18:08:00 by osobol        #+#    #+#                 */
/*   Updated: 2024/03/16 10:50:59 by omersobol     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	found_nl(char *buffer)
{
	int		i;
	bool	is_nl;

	i = 0;
	is_nl = false;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			is_nl = true;
			break ;
		}
		i++;
	}
	return (is_nl);
}

size_t	untilnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	return (i);
}

char	*update_storage(char *save)
{
	char	*temp;

	temp = ft_strdup(save);
	if (temp == NULL)
		return (free(save), NULL);
	free(save);
	save = ft_substr(temp, untilnl(temp), ft_strlen(temp));
	free(temp);
	return (save);
}

char	*read_line(int fd, char *buffer, char *save)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read != 0 && found_nl(save) == false)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == CANT_READ)
			return (free(save), NULL);
		buffer[bytes_read] = '\0';
		save = ft_strjoin(save, buffer);
		if (save == NULL)
			return (NULL);
	}
	if (bytes_read == 0 && save[0] == '\0')
		return (free(save), NULL);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*save = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (save == NULL)
		save = ft_strdup("");
	if (save == NULL)
		return (NULL);
	save = read_line(fd, buffer, save);
	if (save == NULL)
		return (NULL);
	line = ft_substr(save, 0, untilnl(save));
	if (line == NULL)
		return (free(save), save = NULL, NULL);
	save = update_storage(save);
	if (save == NULL)
		return (free(line), NULL);
	return (line);
}

// int main()
// {
// 	int	fd;
// 	int i;
// 	i = 0;
// 	char	*s;

// 	fd = open("testing.txt", O_RDONLY);
// 	// fd = 1;
// 	s = "";
// 	while (s)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);
// 		i++;
// 	}
// 	return (0);
// }
