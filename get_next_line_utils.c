/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: osobol <osobol@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 18:08:38 by osobol        #+#    #+#                 */
/*   Updated: 2024/03/16 10:05:04 by omersobol     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	joined_string = (char *)malloc((ft_strlen(s1) + \
	ft_strlen(s2) + 1) * sizeof(char));
	if (joined_string == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		joined_string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined_string[i + j] = s2[j];
		j++;
	}
	joined_string[i + j] = '\0';
	free(s1);
	return (joined_string);
}

size_t	ft_strlcpy(char *destination, char *source, size_t dest_size)
{
	size_t	src_length;
	size_t	i;

	src_length = ft_strlen(source);
	i = 0;
	if (dest_size != 0)
	{
		while (source[i] && (i < dest_size - 1))
		{
			destination[i] = source[i];
			i++;
		}
		destination[i] = '\0';
	}
	return (src_length);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	substr_len;

	if (start >= ft_strlen(s))
	{
		start = ft_strlen(s);
		len = 0;
	}
	substr_len = ft_strlen(s + start);
	if (substr_len < len)
		len = substr_len;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	sub_string = malloc(len + 1);
	if (sub_string == NULL)
		return (NULL);
	ft_strlcpy(sub_string, &s[start], len + 1);
	return (sub_string);
}

char	*ft_strdup(char *string)
{
	char	*new_string;
	size_t	len;

	len = ft_strlen(string);
	new_string = malloc(len + 1);
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, string, len + 1);
	return (new_string);
}
