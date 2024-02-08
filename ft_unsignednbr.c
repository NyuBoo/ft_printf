/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:46:50 by yanaranj          #+#    #+#             */
/*   Updated: 2023/12/05 13:41:47 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i = ft_putnbr(n / 10);
		if (i == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar(n + '0') == -1)
			return (-1);
		i++;
	}
	return (i);
}
