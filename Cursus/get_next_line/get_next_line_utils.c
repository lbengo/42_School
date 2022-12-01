/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:46:51 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/30 19:21:21 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	strlen_break(char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	a;
	char			*string;

	len = ft_strlen(s1) + ft_strlen(s2);
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (0);
	i = 0;
	a = 0;
	while (s1 && s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2 && s2[a] != '\0')
	{
		string[i] = s2[a];
		a++;
		i++;
	}
	string[i] = '\0';
	return (string);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			s_len;
	char			*substring;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		len = s_len;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while ((len > i) && (s[start] != '\0'))
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*cpy;

	cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!cpy)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
