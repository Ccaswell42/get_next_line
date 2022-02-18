/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:53:02 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:29 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	s2 = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!s2)
		return (0);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = 0;
	l2 = 0;
	i = 0;
	if (!s2)
		return (NULL);
	s3 = (char *)malloc((sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 2)));
	if (!s3)
		return (0);
	while (s1[l1])
	{
		s3[i] = s1[l1];
		i++;
		l1++;
	}
	while (s2[l2])
		s3[i++] = s2[l2++];
	s3[i] = '\0';
	if (s1)
		free((void *)s1);
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc(sizeof(*s) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < start && s[i])
		i++;
	if (s[i] == '\0')
		s2[j] = '\0';
	while (j < len && s[i])
		s2[j++] = s[i++];
	s2[j] = '\0';
	return (s2);
}

int	ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (2);
}
