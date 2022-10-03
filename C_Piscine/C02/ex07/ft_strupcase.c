/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:22:16 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/13 10:12:10 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = (str[i] - 32);
		}
		i++;
	}
	return (str);
}

/*int main()
{
	char str[] = "q Lo q";

	ft_strupcase (str);
	printf ("%s", ft_strupcase(str));
	return 0;
}*/
