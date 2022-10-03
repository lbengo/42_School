/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:33:36 by lbengoec          #+#    #+#             */
/*   Updated: 2022/08/31 16:03:11 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	a;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		if (*str == *to_find)
		{
			i = 0;
			a = 1;
			while (to_find[i] != '\0')
			{
				if (str[i] != to_find[i])
					a = 0;
				i++;
			}
			if (a == 1)
				return (str);
		}
		str++;
	}
	return (0);
}

/*int main()
{
	char str[] = "hola molinete";
	char to_find[] = "";

	printf("%s", ft_strstr(str, to_find));
	return 0;
}*/