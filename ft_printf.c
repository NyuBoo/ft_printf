/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:33:56 by yanaranj          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:03 by yanaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//la funcion esta abajo, aqui solo la invocamos
static int	type_var(char c, va_list elements);

//control del caracter despues del '%'
static int	ft_next_char(char c, va_list elements)
{
	int	let;

	let = 0;
	if (c)
	{
		let = type_var(c, elements);
		if (let == -1)
			return (-1);
		return (let);
	}
	else
	{
		if (write(1, &c, 1) != 1)
			return (-1);
	}
	return (let);
}

//imprime la cadena
static int	ft_print(char const *s, va_list elements, int count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_next_char(s[i + 1], elements);
			if (count == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &s[i], 1) != 1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		count;
	va_list	elements;

	count = 0;
	va_start(elements, str);
	count = ft_print(str, elements, count);
	va_end(elements);
	return (count);
}

static int	type_var(char c, va_list elements)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(elements, int));
	else if (c == 's')
		count += ft_putstr(va_arg(elements, char *));
	else if (c == 'p')
		count += ft_pointer(va_arg(elements, unsigned long long));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(elements, unsigned long long));
	else if (c == 'u')
		count += ft_unsignednbr(va_arg(elements, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_hexadecimal(va_arg(elements, unsigned int), 16, c);
	else if (c == '%')
	{
		if (ft_putchar('%') == -1)
			return (-1);
		count += 1;
	}
	return (count);
}
/*
int main()
{

//	char	c = 'v';
//	char	*str = "aa";
//	int		digit = -1000000000;
//	int		x = 14523;
//	int		u = 12;

	int		org = 0;
	int		mine = 0;

	org = printf("O:%x\n", -10);
	mine = ft_printf("M:%x\n", -10);
//	org = printf("%p\n", (void*)-987654321);
//	mine = ft_printf("%p\n", (void*)-987654321);

	printf("%d\n%d\n", org, mine);

	return (0);
}
*/
