/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:53:20 by antandre          #+#    #+#             */
/*   Updated: 2024/07/17 11:28:40 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main() {
    char c = 'A';
    char *str = "Hello, World!";
    char *null = NULL;
    void *ptr = str;
    void *nil = 0;
    int d = 42;
    int i = -42;
    unsigned int u = 3000000000;
    unsigned int x = 255;
    unsigned int X = 255;

    // Testing %c
    printf("Testing %%c:\n");
    printf(": %d \n\n", printf("Printf: [%c]\n", c));
    printf(": %d \n\n", ft_printf("printf: [%c]\n", c));

    // Testing %s
    printf("Testing %%s:\n");
    printf(": %d \n\n", printf("Printf: [%s]\n", str));
    printf(": %d \n\n", ft_printf("printf: [%s]\n", str));
    printf(": %d \n\n", printf("Printf: [%s]\n", null));
    printf(": %d \n\n", ft_printf("printf: [%s]\n", null));

    // Testing %p
    printf("Testing %%p:\n");
    printf(": %d \n\n", printf("Printf: [%p]\n", ptr));
    printf(": %d \n\n", ft_printf("printf: [%p]\n", ptr));
    printf(": %d \n\n", printf("Printf: [%p] [%p]\n", nil, nil));
    printf(": %d \n\n", ft_printf("printf: [%p] [%p]\n", nil, nil));

    // Testing %d
    printf("Testing %%d:\n");
    printf(": %d \n\n", printf("Printf: [%d]\n", d));
    printf(": %d \n\n", ft_printf("printf: [%d]\n", d));

    // Testing %i
    printf("Testing %%i:\n");
    printf(": %d \n\n", printf("Printf: [%i]\n", i));
    printf(": %d \n\n", ft_printf("printf: [%i]\n", i));

    // Testing %u
    printf("Testing %%u:\n");
    printf(": %d \n\n", printf("Printf: [%u]\n", u));
    printf(": %d \n\n", ft_printf("printf: [%u]\n", u));

    // Testing %x
    printf("Testing %%x:\n");
    printf(": %d \n\n", printf("Printf: [%x]\n", x));
    printf(": %d \n\n", ft_printf("printf: [%x]\n", x));

    // Testing %X
    printf("Testing %%X:\n");
    printf(": %d \n\n", printf("Printf: [%X]\n", X));
    printf(": %d \n\n", ft_printf("printf: [%X]\n", X));

    // Testing %%
    printf("Testing %%%%:\n");
    printf(": %d \n\n", printf("Printf: [%%]\n"));
    printf(": %d \n\n", ft_printf("printf: [%%]\n"));

    return (0);
}
