/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:21:55 by yanaranj          #+#    #+#             */
/*   Updated: 2023/12/05 13:41:26 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_min(int n)
{
	(void)n;
	if (write (1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0 && ++i)
	{
		if (ft_putchar('-') != 1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		if (i == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar('0' + n) == -1)
			return (-1);
		i++;
	}
	return (i);
}
