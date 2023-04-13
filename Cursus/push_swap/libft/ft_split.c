/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:10:05 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cut(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			j++;
			continue ;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	start;
	unsigned int	a;

	str = (char **)malloc(sizeof(char *) * (ft_cut(s, c) + 1));
	if (!str)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			str[a] = ft_substr(s, start, i - start);
			a++;
			continue ;
		}
		i++;
	}
	str[a] = NULL;
	return (str);
}
