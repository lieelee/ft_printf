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
#include "libft/libft.h"
#include <stdarg.h>

#define SPECIFIER "cspdiuxXnfge"
#define LENGTH "hl"
#define FLAG "-+0#*.' "
#define WIDTH "*0123456789"
#define PRECISION "*0123456789"
#define LEN_HL "diouxXn"
#define LEN_L   "efg"
#define WRONG_LEN_HL "cspnfge"
#define WRONG_LEN_L "cspdiuxXn"

typedef struct  s_format
{
    int         length[2];
    char        flag[8]; // it can have up to 7 flags in one format
    int         width;
    int         prec;
    char        speci;
}               f_format;

