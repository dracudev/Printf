/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:45:46 by antandre          #+#    #+#             */
/*   Updated: 2024/07/12 12:03:02 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_conv(char c, va_list *args, int *len, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, int), len);
	else if (c == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else
		(*i)--;
}

static int	ft_percent(char const *str, int i, va_list *args, int *len)
{
	if (str[i + 1] == '\0')
		ft_putchar('%', len);
	else if (str[i + 1] == '%')
	{
		ft_putchar('%', len);
		i++;
	}
	else if (str[i + 1] != '\0' && (str[i + 1] == 'c' || str[i + 1] == 's'
			|| str[i + 1] == 'p' || str[i + 1] == 'd' || str[i + 1] == 'i'
			|| str[i + 1] == 'u' || str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		i++;
		ft_check_conv(str[i], args, len, &i);
	}
	else
		ft_putchar('%', len);
	return (i);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			i = ft_percent(str, i, &args, &len);
		else
			ft_putchar((char)str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
