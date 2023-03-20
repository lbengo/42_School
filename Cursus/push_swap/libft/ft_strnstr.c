/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:55:04 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/16 07:52:21 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEFINICIÓN:
La siguiente función busca en el primer string en otro string, es decir si la
frase es "hola que tal" y lo que pretendo buscar es "que", el resultado sería
"que tal". En el caso de que busque "qui", el resulado sería null ya que la
palabra no existe en mi frase.
----------------------------------------------------------------------------- */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/*int main(void)
{
	const char haystack[] = "hod ue tal como estamos";
	const char needle[] = "ue";

	printf("%s \n", ft_strnstr(haystack, needle, 6));
	printf("%s \n", strnstr(haystack, needle, 6));
	return (0);
}*/
