/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:36:19 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/11 15:56:09 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				i++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (1);
}

/*int main()
{
	char str[] = "ydj1sl";
	printf("%d", ft_str_is_lowercase(str));
	return 0;
}*/
