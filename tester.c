/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:09:45 by antandre          #+#    #+#             */
/*   Updated: 2024/07/10 13:40:58 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	ch;
	char	*str;
	int	i;
	int	d;
	unsigned int u;


	ch = 'A';
	str = "Hello, world!";
	i = -42;
	d = -42;
	u = 42;
	ft_printf("%c %s", ch, str);
	ft_printf("%i %d %u", i, d, u);
	printf("%i %d %u", i, d, u);
}
