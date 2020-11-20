/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 00:04:37 by yelee             #+#    #+#             */
/*   Updated: 2020/05/09 00:04:37 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdarg.h>

#define SPECIFIER "cspdiuxXnfge"
#define LENTH "hl"
#define FLAG "-+0#*.' "

typedef struct  s_format
{
    int         lengh[4];
    char        flag[8];
    int         width;
    int         prec;
    char        speci;
}               f_format;

