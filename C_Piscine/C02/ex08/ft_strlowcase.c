/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:17:28 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/11 20:27:06 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] + 32);
		}
		i++;
	}
	return (str);
}

/*int	main()
{
	char str[] = "Q lO q";

	ft_strlowcase (str);
	printf ("%s", ft_strlowcase(str));
	return 0;
}*/
