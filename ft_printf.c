/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:45:46 by antandre          #+#    #+#             */
/*   Updated: 2024/07/04 18:15:31 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_conv(char c, va_list *args, int *len, int *i)
{
	if (c == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (c == 's')
		ft_string(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_number(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, int), len);
	else if (c == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (c == '%')
		ft_putchar_len('%', len);
	else
		(*i)--;
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
		{
			i++;
			ft_check_conv(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
