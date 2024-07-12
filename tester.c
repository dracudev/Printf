/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:09:45 by antandre          #+#    #+#             */
/*   Updated: 2024/07/11 14:51:47 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void) 
{
    // Testing %c
    char c = 'A';
    printf("Testing %%c:\n");
    printf("printf:    [%c]\n", c);
    ft_printf("ft_printf: [%c]\n\n", c);

    // Testing %s
    char *str = "Hello, World!";
    char *null = NULL;
    printf("Testing %%s:\n");
    printf("printf:    [%s]\n", str);
    ft_printf("ft_printf: [%s]\n\n", str);
    printf("printf: [%s]\n", null);
    ft_printf("ft_printf: [%s]\n\n", null);

    // Testing %p
    void *ptr = str;
    printf("Testing %%p:\n");
    printf("printf:    [%p]\n", ptr);
    ft_printf("ft_printf: [%p]\n\n", ptr);
    printf("printf: [%p] [%p]\n", 0, 0);
    ft_printf("ft_printf: [%p] [%p]\n\n", 0, 0);

    // Testing %d
    int d = 42;
    printf("Testing %%d:\n");
    printf("printf:    [%d]\n", d);
    ft_printf("ft_printf: [%d]\n\n", d);

    // Testing %i
    int i = -42;
    printf("Testing %%i:\n");
    printf("printf:    [%i]\n", i);
    ft_printf("ft_printf: [%i]\n\n", i);

    // Testing %u
    unsigned int u = 3000000000;
    printf("Testing %%u:\n");
    printf("printf:    [%u]\n", u);
    ft_printf("ft_printf: [%u]\n\n", u);

    // Testing %x
    unsigned int x = 255;
    printf("Testing %%x:\n");
    printf("printf:    [%x]\n", x);
    ft_printf("ft_printf: [%x]\n\n", x);

    // Testing %X
    unsigned int X = 255;
    printf("Testing %%X:\n");
    printf("printf:    [%X]\n", X);
    ft_printf("ft_printf: [%X]\n\n", X);

    // Testing %%
    printf("Testing %%%%:\n");
    printf("printf:    [%%]\n");
    ft_printf("ft_printf: [%%]\n\n");
    /*printf("printf: [%]\n");
    ft_printf("ft_printf: [%]\n");
    printf("printf: [%%%]\n");
    ft_printf("ft_printf: [%%%]\n");
    printf("printf: [w%w%w%w]\n");
    ft_printf("ft_printf: [w%w%w%w]\n\n");*/

    return (0);
}
