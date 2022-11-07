/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:55:11 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/07 13:22:59 by lbengoec         ###   ########.fr       */
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

int	ft_printf(char const *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr_10(int n, char *base);
int	ft_putnbr_16_10u(unsigned int n, char *base);
int	ft_putpointer(unsigned long long int n, char *base);

#endif
