/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:25:41 by yanaranj          #+#    #+#             */
/*   Updated: 2023/12/06 16:31:06 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int nbr, unsigned int base, char flag)
{
	int				count;
	char			*symbols;

	if (flag == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	count = 0;
	if (nbr < base)
	{
		if (ft_putchar(symbols[nbr]) == -1)
			return (-1);
	}
	else if (base > 1)
	{
		count = ft_hexadecimal(nbr / base, base, flag);
		if (count == -1 || ft_hexadecimal(nbr % base, base, flag) == -1)
			return (-1);
	}
	count++;
	return (count);
}
