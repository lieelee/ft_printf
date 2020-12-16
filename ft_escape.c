/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:19:48 by yelee             #+#    #+#             */
/*   Updated: 2020/05/09 19:19:48 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
'str + i' is the address that has '/'
Hence, I should define another int to adjust address to actual flag not /
It's 'str + i + 1' Let's define this address as 'j' 
However, If 'j' is also '/', previous '/' is not escape char but the char
that tells me it is to write just a char that is used as escape char as well. 
So, there are if-else cases here.
*/
int     ft_escape(va_list args, char *str, int i)
{

}