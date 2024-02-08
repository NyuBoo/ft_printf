/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:33:28 by yanaranj          #+#    #+#             */
/*   Updated: 2023/12/06 12:51:27 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(char const *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_hexadecimal(unsigned int nbr, unsigned int base, char flag);
int		ft_unsignednbr(unsigned int n);
int		ft_pointer(unsigned long long n);

#endif
