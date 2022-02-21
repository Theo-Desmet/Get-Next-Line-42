/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 09:15:47 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/06 16:17:11 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_mem(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char	*free_line(char *line, char *mem)
{
	char	*newline;
	int		lline;
	int		lmem;

	if (!line || !mem)
		return (free_line(line, NULL));
	newline = NULL;
	lline = ft_strlen(line);
	lmem = ft_strlen(mem);
	newline = malloc(sizeof(char) * (lline - lmem + 1));
	if (!newline)
		return (NULL);
	ft_memcpy(newline, line + lmem, lline - lmem + 1);
	free(line);
	return (newline);
}

char	*read_line(char *line, int fd)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = malloc(sizeof(char *) * BUFFER_SIZE +1);
	if (!buf)
		return (0);
	*buf = 0;
	while (!ft_strchr(buf, '\n') && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (free_mem(buf, line));
		buf[ret] = '\0';
		if (ret)
			line = ft_strjoin_free(line, buf);
	}
	free(buf);
	if (!ret && !line)
		return (NULL);
	if (!ret && !*line)
		return (free_mem(line, NULL));
	return (line);
}

char	*get_line(char *line)
{
	int		i;
	char	*mem;

	i = 0;
	if (!line || *line == 0 || !*line)
		return (NULL);
	mem = ft_strdup(line);
	while (mem[i] != '\n' && mem[i] != '\0')
		i++;
	mem[i + 1] = 0;
	return (mem);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*mem;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (!line[fd])
		line[fd] = read_line(line[fd], fd);
	if (line[fd])
	{
		while (line[fd][i] != '\n' && line[fd][i] != '\0')
			i++;
		if (line[fd][i] != '\n')
			line[fd] = read_line(line[fd], fd);
		mem = get_line(line[fd]);
	}
	if (!line[fd])
		return (NULL);
	line[fd] = free_line(line[fd], mem);
	return (mem);
}
/*
int	main()
{
	int fd;
	int fd2;
	char *tab;

	fd = open("./test", O_RDONLY);
	fd2 = open("./test2", O_RDONLY);
	while (1)
	{
		tab = get_next_line(fd);	
		if (!tab)
			return(0);
		printf("%s", tab);
		free(tab);

		tab = get_next_line(fd2);	
		if (!tab)
			return(0);
		printf("%s", tab);
		free(tab);
	}
}*/
