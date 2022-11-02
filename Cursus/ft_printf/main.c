/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:36:14 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/02 23:36:35 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main (void)
{
	ft_printf("hola chanchito feliz %c %s %d %i %u  oi", 'a', "hola",2368496, 1234, -144);
	//printf("%i", ft_printf("hola chanchito feliz %s oi", 12));
}