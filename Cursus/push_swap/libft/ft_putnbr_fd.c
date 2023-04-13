/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:47:43 by lbengoec          #+#    #+#             */
/*   Updated: 2023/04/13 13:09:55 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = n * (-1);
		ft_putchar_fd('-', fd);
	}
	if (n >= 10)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd(((n % 10) + '0'), fd);
}
