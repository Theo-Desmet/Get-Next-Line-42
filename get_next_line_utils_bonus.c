/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdesmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:05:49 by tdesmet           #+#    #+#             */
/*   Updated: 2022/01/06 16:20:58 by tdesmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || !str || *str == '\0')
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *) s;
	if (c > 256)
		c %= 256;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i++;
	}
	if (c == 0)
		return (&ptr[i]);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	source = (unsigned char *) src;
	dest = (unsigned char *) dst;
	i = 0;
	if (!dst || !src)
		return (NULL);
	if (n == 0)
		return (dst);
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char				*ptr;
	unsigned int		i;
	unsigned int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = malloc(sizeof(char) * i + sizeof(char) * j + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, i);
	ft_memcpy(ptr + i, s2, j);
	ptr[i + j] = 0;
	if (s1)
		free(s1);
	return (ptr);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (!s || !*s)
		return (NULL);
	ptr = malloc(ft_strlen(s) + 2);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
