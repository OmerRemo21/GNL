/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osobol <osobol@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 18:08:00 by osobol        #+#    #+#                 */
/*   Updated: 2024/03/13 11:06:03 by omersobol     ########   odam.nl         */
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
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = ft_strjoin(save, buffer);
	}
	if (bytes_read == 0 && save[0] == '\0')
	{
		free(save);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (save == NULL)
		save = ft_strdup("");
	save = read_line(fd, buffer, save);
	if (save == NULL)
		return (NULL);
	line = ft_substr(save, 0, untilnl(save));
	save = update_storage(save);
	return (line);
}

//int main()
//{
//	int	fd;
//	int i;
//	i = 0;

//	fd = open("testingfile.txt", O_RDONLY);
//	fd = 1;
//	while (i < 14)
//	{
//		printf("%s", get_next_line(fd));
//		i++;
//	}
//	return (0);
//}