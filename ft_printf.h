/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:07:43 by antandre          #+#    #+#             */
/*   Updated: 2024/07/10 12:06:57 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

void			ft_putchar(char ch, int *len);
void			ft_putstr(char *args, int *len);

void			ft_number(int number, int *len);
void			ft_hexadecimal(unsigned int x, int *len, char x_or_x);
void			ft_unsigned_int(unsigned int u, int *len);
void			ft_pointer(size_t pointer, int *len);

int				ft_printf(const char *str, ...);

#endif
