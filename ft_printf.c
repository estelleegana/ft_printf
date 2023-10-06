/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:22:15 by estegana          #+#    #+#             */
/*   Updated: 2023/06/27 16:22:18 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int valid(char c)
{
    char    c;

    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c = 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
        return 1;
    return 0
}

int type(va_list args, char c)
{
    int len;

    len = 0;
    if (c == 'c')
        len = ft_putchar(va_arg(args, int));
    if (c == 's')
        len = ft_putstr(va_arg(args, char *));
    if (c == 'p')
        len = ft_putptr(va_arg(args, unsigned long));
    if (c == 'd' || c == 'i')
        len = ft_putnbr(va_arg(args, int));
    if (c == 'u')
        len = ft_putunsigned(va_arg(args, unsigned int));
    if (c == 'x' || c == 'X')
        len = ft_ft_puthexa(va_arg(args, char *));
    if (c == '%')
        len = ft_putchar('%');
    return(len);
}

int ft_printf(const char *format, ...)
{
    int i;
    int nb_char;
    va_list args;

    i = 0;
    nb_char = 0;
    va_start(args, format);
    if (!format)
        return 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            while (format[i] && format[i] == ' ')
                i++;
            if (valid(format[i]))
                nb_char += tpe(args, format[i]);
            i++;
        }
        else
            nb_char += ft_putchar(args, formatt[i]);
    }
    va_end(args);
    return (nb_char);
}