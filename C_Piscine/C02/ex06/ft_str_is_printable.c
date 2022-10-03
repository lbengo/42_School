/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:24:38 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/13 10:11:43 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] >= 32 && str[i] <= 126)
				i++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (1);
}

/*int main ()
{
	char str[] = "disáodl idfh";
	printf("%d", ft_str_is_printable(str));
	return 0;
}*/
