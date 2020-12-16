/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 00:10:59 by yelee             #+#    #+#             */
/*   Updated: 2020/05/09 00:10:59 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function returns a lengh of a format.
ex)printf("%08.5f\n hello", 0.1234567)
*/
int     format_len(va_list args, char *str, int i)
{
    f_format    *a_format;

    a_format = 





    if (!ft_strchr(SPECIFIER, str)) //If there's no specifier
        return (0) //error. it prints nothings
    if else (ft_strchr(SPECIFIER, str) && ) // specifier without anything to match
    
}

/*
When printf function successful return, It return the number of characters printed 
(excluding the null byte used to end output to strings).
*/

int     printf_len(va_list args, char *str)
{
    int     i;
    int     len;

    len = 0;
    i = 0;
    while (str[i])
    {
        if (str[i] == '%') //format specifier char
        {
            ++i;
            len = len + format_len(args, str, i); // i for address in the string after %
            // ft_format returns how many var they have used. 
            // It becomes new address
            ++i;
        }
        if (str[i] != '%' && str[i])// otherwise, just print that out with write func. 
        {
            write(1, str + i, 1);
            ++i;
            ++len;
        }
    }
    return (len);
}

int     ft_printf(char *str, ...)
{
    int         len;
    va_list     args;

    va_start(args, str); //initialize args to str 
    len = printf_len(args, str);
    va_end(args);
    return (len);
} 