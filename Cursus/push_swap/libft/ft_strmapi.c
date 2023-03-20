/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:22:23 by lbengoec          #+#    #+#             */
/*   Updated: 2022/09/21 11:26:09 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	cpy = ft_strdup(s);
	if (!cpy)
		return (0);
	while (cpy[i] != '\0')
	{
		cpy[i] = f(i, cpy[i]);
		i++;
	}
	return (cpy);
}
