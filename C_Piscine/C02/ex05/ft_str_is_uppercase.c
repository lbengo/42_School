/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:52:07 by lbengoec          #+#    #+#             */
/*   Updated: 2022/07/11 17:23:05 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
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
	char str[] = "KLdK";
	printf("%d", ft_str_is_uppercase(str));
	return 0;
}*/
