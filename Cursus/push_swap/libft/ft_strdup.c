/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 09:52:25 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 11:10:03 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La función strdup asigna suficiente memoria para una copia de la cadena s1,
realiza la copia y devuelve un puntero a la misma. El puntero puede utilizarse
posteriormente como argumento para la función free(3).
----------------------------------------------------------------------------- */

#include "libft.h"

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

/* int main(void)
{
	const char s1[] = "hola";
	printf("%s", ft_strdup(s1));
	return (0);
} */
