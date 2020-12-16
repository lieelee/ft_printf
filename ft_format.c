/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:19:26 by yelee             #+#    #+#             */
/*   Updated: 2020/05/09 19:19:26 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This functions returns the length of format
'str + i' is the address that has '%'
Hence, I should define another int to adjust address to actual flag not %.
Let's define this flag address(str + i + 1) as j 
The format is '%[flag][width][.precision][length][specifier]
flag        : - + 0 # * . ' space
(if there are - 0 together, 0 is ignored. not padding with zero but left listed.)
width       : int *
precision   : int *
length      : h hh l ll
specifier   : c s p d i u x X n f g e
printf("%sworld"hello)
*/
int     ft_format(va_list args, char *str, int i)
{
    int     i;
    f_format    F_format;  //need to initialize **

    i = 0;
    if (!ft_strchr(SPECIFIER, str)) //If there's no specifier
        return (0) //error
    else // need error check / if ~
    {
        while (str[i] == FLAG) // all flags detect and save 
        {
            F_format->flag = str[i];
            ++i;
        }
        (ft_isalnum(ft_atoi(str)) || str[i] == '*') ? F_format->width = str[i], ++i : i; //width check
        (str[i] == '.') ? F_format->prec = str[++i], ++i : i; // precision check
        while (str[i] == LENTH) // all flags detect and save / but what if it's 't'?
        {
            F_format->len = str[i];
            ++i;
        }
        F_format->speci = str[i];
    }
    return (i);
}

//error check if all the flags... are correct 
int     ft_format_error(f_format F_format)
{
    if (F_format->prec = )

}