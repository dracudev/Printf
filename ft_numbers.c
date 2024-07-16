/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:50 by antandre          #+#    #+#             */
/*   Updated: 2024/07/16 17:49:52 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, int *len)
{
	int	res;

	if (nbr == -2147483648)
	{
		res = write(1, "-2147483648", 11);
		(*len) += 11;
		return (res);
	}
	if (nbr < 0)
	{
		res = ft_putchar('-', len);
		res = ft_putnbr(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			res = ft_putnbr(nbr / 10, len);
		res = ft_putchar((nbr % 10) + '0', len);
	}
	return (res);
}

int	ft_unsigned_int(unsigned int u, int *len)
{
	if (u > 9)
		if (ft_unsigned_int(u / 10, len) == -1)
			return (-1);
	if (ft_putchar((u % 10) + '0', len) == -1)
		return (-1);
	return (0);
}

int	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		(*len) += 5;
		return (0);
	}
	base = "0123456789abcdef";
	i = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	(*len) += 2;
	while (ptr != 0)
	{
		str[i++] = base[ptr % 16];
		ptr = ptr / 16;
	}
	while (i--)
	{
		if (ft_putchar(str[i], len) == -1)
			return (-1);
	}
	return (0);
}

int	ft_hexadecimal(unsigned int x, int *len, char x_X)
{
	char	str[25];
	char	*base;
	int		i;

	if (x_X == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		if (ft_putchar('0', len) == -1)
			return (-1);
		return (0);
	}
	while (x != 0)
	{
		str[i++] = base[x % 16];
		x = x / 16;
	}
	while (i--)
	{
		if (ft_putchar(str[i], len) == -1)
			return (-1);
	}
	return (0);
}
