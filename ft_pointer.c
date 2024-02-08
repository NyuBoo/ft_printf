/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:17:42 by yanaranj          #+#    #+#             */
/*   Updated: 2023/12/05 13:38:28 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_punt_hexa(unsigned long long n, char *base)
{
	char	c;

	if (n >= 16)
		ft_punt_hexa(n / 16, base);
	c = base[n % 16];
	if (ft_putchar(c) == -1)
		return (-1);
	return (0);
}

static int	ptr_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long long nbr)
{
	static char	*base = "0123456789abcdef";

	if (write(1, "0x", 2) != 2)
		return (-1);
	if (ft_punt_hexa(nbr, base) == 0)
		return (ptr_len(nbr) + 2);
	return (-1);
}
