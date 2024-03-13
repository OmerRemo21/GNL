/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: osobol <osobol@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/18 17:51:52 by osobol        #+#    #+#                 */
/*   Updated: 2024/03/13 10:36:19 by omersobol     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define CANT_READ -1

bool	found_nl(char *buffer);
size_t	untilnl(char *str);
char	*get_next_line(int fd);

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *destination, char *source, size_t dest_size);
char	*ft_strdup(char *string);

#endif