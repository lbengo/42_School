/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbengoec <lbengoec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:55:11 by lbengoec          #+#    #+#             */
/*   Updated: 2022/11/02 20:53:47 by lbengoec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ***************************** LIBRERIAS ********************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>	// Librería que gestiona las variádicas
# include <stdlib.h>

/* ***************************** FUNCIONES ********************************** */

int		ft_printf(char const *format, ...);
void	ft_putchar(int c);
void	ft_putstr(char *s);
int	ft_putnbr_10_integer(int n);


#endif
