/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:41:32 by lbengoec          #+#    #+#             */
/*   Updated: 2023/03/21 13:07:46 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cut(char const *s, char c, char d)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != d)
		{
			while (s[i] != '\0' && s[i] != c && s[i] != d)
				i++;
			j++;
			continue ;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c, char d)
{
	char			**str;
	unsigned int	i;
	unsigned int	start;
	unsigned int	a;

	str = (char **)malloc(sizeof(char *) * (ft_cut(s, c, d) + 1));
	if (!str)
		return (NULL);
	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != d)
		{
			start = i;
			while (s[i] != '\0' && s[i] != c && s[i] != d)
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

/* int main(void)
{
	char const s[] = "  hola  que pasa";
	char c;
	char **result;

	c = ' ';
	result = ft_split(s, c);
	int check = -1;
	while (result[++check])
		printf("line [%d] -> %s\n", check, result[check]);
	//printf("%s", ft_split(s, c));
	return (0);
} */
