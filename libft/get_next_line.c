/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:35:16 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 19:01:00 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_line_buffer(char *buffer, char *line)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, line);
	free(buffer);
	if (!tmp)
		return (free(line), NULL);
	return (tmp);
}

char	*read_file_and_maj_stash(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		stash = add_line_buffer(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*take_line_to_stash(char *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	if (!line)
		return (free(stash), NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*del_line_to_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	free(stash);
	stash = NULL;
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_file_and_maj_stash(fd, buffer);
	if (!buffer)
		return (NULL);
	line = take_line_to_stash(buffer);
	buffer = del_line_to_stash(buffer);
	return (line);
}

// #include <fcntl.h>
// #include <stdlib.h>
// #include <stdio.h>
// int main()
// {
//     int fd;
//     char *line;
// 	//int	count = 1;

//     fd = open("test.txt", O_RDONLY);
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line);
//     }
//		line = get_next_line(fd);
//		printf("%s", line);
//     close(fd);
//     return (0);
// }