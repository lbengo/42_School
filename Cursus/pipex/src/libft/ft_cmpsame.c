/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmpsame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:52:58 by lbengoec          #+#    #+#             */
/*   Updated: 2023/05/29 10:39:57 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmpsame(const char *s1, const char *s2)
{
	unsigned int	i;
	size_t			a;

	i = 0;
	a = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
		a++;
	}
	if (s2[i] == '\0' || s2[i] == '\n')
		return (0);
	return (1);
}
