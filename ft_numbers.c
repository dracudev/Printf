/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:14:50 by antandre          #+#    #+#             */
/*   Updated: 2024/07/12 11:07:12 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10, len);
		ft_putchar((nbr % 10) + '0', len);
	}
}

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u > 9)
		ft_unsigned_int(u / 10, len);
	ft_putchar((u % 10) + '0', len);
}

void	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}

void	ft_hexadecimal(unsigned int x, int *len, char x_X)
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
		ft_putchar('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}
