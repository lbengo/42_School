/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:55:11 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/02 23:57:58 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ***************************** LIBRERIAS ********************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>	// Librería que gestiona las variádicas
# include <stdlib.h>

/* ***************************** FUNCIONES ********************************** */

int		ft_printf(char const *format, ...);
int     ft_putchar(int c);
void	ft_putstr(char *s);
int     ft_putnbr_10_decimal(long int n);
int     ft_putnbr_10_integer(int n);
int     ft_putnbr_10_positive(unsigned int n);


#endif
