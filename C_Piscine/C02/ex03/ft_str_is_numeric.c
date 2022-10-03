/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:47:22 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/11 15:00:29 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9')
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
	char str[] = "728/";
	printf("%d", ft_str_is_numeric(str));
	return 0;
}*/
