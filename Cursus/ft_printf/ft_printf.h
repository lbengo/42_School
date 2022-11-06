/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:55:11 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/04 21:51:31 by lbengoec         ###   ########.fr       */
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
int     ft_putstr(char *s);
int     ft_putnbr_10_d(int n);
int     ft_putnbr_10_i(int n);
int     ft_putnbr_10_u(unsigned int n);
int    ft_putnbr_16(unsigned int n, char *base);




#endif
