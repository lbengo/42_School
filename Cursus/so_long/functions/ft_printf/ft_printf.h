/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:55:11 by lbengoec          #+#    #+#             */
/*   Updated: 2023/02/28 12:15:25 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ***************************** LIBRERIAS ********************************** */

# include <unistd.h>
# include <stdarg.h>

/* ***************************** FUNCIONES ********************************** */

int		ft_printf(char const *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_putnbr_10(int n, char *base);
int		ft_putnbr_10_u(unsigned int n, char *base);
int		ft_putnbr_16(unsigned int n, char *base);
int		ft_putpointer(unsigned long long int n, char *base);
size_t	ft_strlen(const char *s);

/* ***************************** CONSTANTES ********************************* */

# define BASEDECIMAL "0123456789"
# define BASELOWER "0123456789abcdef"
# define BASEUPPER "0123456789ABCDEF"

#endif
