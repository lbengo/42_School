/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 08:05:47 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:10:24 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		string[i] = s2[a];
		a++;
		i++;
	}
	string[i] = '\0';
	return (string);
}
