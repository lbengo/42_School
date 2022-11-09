/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:07:09 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/09 11:15:38 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
Reserva (con malloc(3)) y devuelve una substring de la string ’s’. La
substring empieza desde el índice ’start’ y tiene una longitud máxima ’len’.
----------------------------------------------------------------------------- */

#include "libft.h"

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

/* int main(void)
{
	char const s[] = "hola que tal";
	printf("mi función = %s", ft_substr(s, 2, 6));
	return (0);
} */
