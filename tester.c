/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:09:45 by antandre          #+#    #+#             */
/*   Updated: 2024/07/10 12:20:51 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	ch;
	char	*str;

	ch = 'A';
	str = "Hello, world!";
	ft_printf("%c %s", ch, str);
}
