/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaswell <ccaswell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:42:20 by ccaswell          #+#    #+#             */
/*   Updated: 2021/11/17 17:15:06 by ccaswell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*do_n(char *str)
{
	int		i;
	char	*do_n;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\0')
		i++;
	do_n = ft_substr(str, 0, i);
	if (!do_n)
		return (NULL);
	if (do_n[0] == '\0')
	{
		free(do_n);
		return (NULL);
	}
	return (do_n);
}

char	*posle_n(char *str)
{
	char	*new;
	int		a;
	int		i;

	a = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[a] != '\n' && str[a])
		a++;
	if (str[a] == '\0')
	{
		free(str);
		return (NULL);
	}
	a++;
	new = malloc (sizeof(char) * (ft_strlen(str) - a + 2));
	if (!new)
		return (NULL);
	while (str[a] != '\0')
		new[i++] = str[a++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_read(int fd, char *str_st)
{
	int		t;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	t = 1;
	while (t)
	{
		t = read(fd, buff, BUFFER_SIZE);
		if (t < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[t] = '\0';
		if (str_st == 0)
			str_st = ft_strdup(buff);
		else
			str_st = ft_strjoin(str_st, buff);
		if ((ft_strchr(str_st, '\n') == 1) || (t < BUFFER_SIZE))
			break ;
	}
	free(buff);
	return (str_st);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*str_st[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_st[fd] = ft_read(fd, str_st[fd]);
	if (str_st[fd] == NULL)
	{
		 free(str_st[fd]);
		return (NULL);
	}
	ret = do_n(str_st[fd]);
	str_st[fd] = posle_n(str_st[fd]);
	return (ret);
}
