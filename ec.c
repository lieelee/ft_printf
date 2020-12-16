#include <stdio.h>
#include "ft_printf.h"
// int main()
// {
//     int i = 0;
//     char *str = "hello";
//     char s[5];

//     str[i] == 'h' ? s[i] = str[i], i++ : i == 10;
//     printf("%d\n", i);
//     printf("%08.9ks", s); 
//     return (0);
// } 
//when there is wrong specifier, it just ignores all the flags and print?

// char    *ft_str(char *str, int i)
// {
//     int j = 0;
//     while (str[j])
//     {
//         if (str[j] == i)
//             return str + j;
//         j++;
//     }
//     return (NULL);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	int		i;
// 	char	*src;

// 	i = 0;
// 	src = (char *)str;
// 	while (c != src[i] && src[i] != '\0')
// 		i++;
// 	if (src[i] == c)
// 		return (&src[i]);
// 	else
// 		return (NULL);
// }

// #define STR "helloworld"
// int main(void)
// {
    // printf("hello%2 dworld\n", 12);
    // //-> hello  dworld. % and 2 are ignored. 
    // printf("hello %2d dworld\n", );
    // //error. specifier without va_list
    // printf("hello%2 dworld\n", );
    // //error no specifier without va_list
    // printf("hello%2 dworld\n");
    //-> hello  dworld.  % and 2 are ignored.
    //printf("%%d\n");
    //printf("%-10 d", 1);

    // ft_str(STR, 'h') != NULL ? printf("ok\n") : printf("no\n");
    // if (STR[1])
    //     printf("It's not null\n");
    // printf("%h2d\n", 2);
    // char    *i;
    // char    *a;

    // a = ft_strchr(STR, 'w');
    // i = ft_strchr(STR, 'w');
    // printf("string: %s\n1.address: %p\n2.address: %p\n", i, STR + 5, a);
    // printf("3.call using address: %c\n", *i);
    // printf("4. next character by address: %c\n", *(i+1));
    // STR[1] == 'e' ? printf("Its ok\n") : printf("Its not\n");

    //STR[1] != 'e' ? printf("ok\n") : STR[2] != 'l' ? printf("ok2\n") : printf("wrong"); 
//     STR[1] ? (printf("its not null\n")&&printf("dd")): (printf("its null")&&continue);
//     return (0);
// }
char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*src;

	i = 0;
	src = (char *)str;
	while (c != src[i] && src[i] != '\0')
		i++;
	if (src[i] == c)
		return (&src[i]);
	else
		return (NULL);
}

// void    initialize(f_format *f)
// {
//     f->length[0] = 0;
//     f->flag[0] = NULL; //how do i initialize this? 
//     f->width = 0;
//     f->prec = 6; //default precision is 6, then should i initialize this to 6?
//     f->speci = NULL;
// }

// %[flags][width][.precision][length]specifier. ORDER! 
int    set_format(f_format *f, char *str)
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    // find a specifier first 
    while (ft_strchr(SPECIFIER, str[i]) != NULL)
        ++i;
    //str[i] is one of specifier if not it ddnt find any -> error 
    //ft_strchr(SPECIFIER, str[i]) == NULL ? ft_error("error") : f->speci = str[i];
    // index i indicates a specifier from now.
    // d, i, o, u, x, X, and n types for h hh ll
    // e, f, g, types for l
    // %%h2.2#
    while (ft_strchr(FLAG, str[j])) // one format can take up to 7 flags 
    {
        f->flag[j] = str[j];
        ++j;        
    }
    ft_strchr(WIDTH, str[j]) ? (f->width = str[j] && ++j) : j;
    str[j] == '.' ? ++j : j;
    ft_strchr(PRECISION, str[j]) ? (f->prec = str[j] && ++j) : j;
    ft_strchr(LENGTH, str[j]) ? (f->length[0] = str[j] && ++j) : j;
    ft_strchr(LENGTH, str[j]) ? (f->length[1] = str[j] && ++j) : j;
    j == i ? j : ft_error("error");
    // h hh ll , l
    (f->length[0] == 'l' && f->length[1] != 'l' && ft_strchr(WRONG_LEN_L, f->speci)) ? ft_error("error") : j;
    (ft_strchr(LENGTH, f->length[0]) && ft_strchr(WRONG_LEN_HL, f->speci)) ? ft_error("error") : j;

    return (i);
}

int     format_len(char *str, int i)
{
    f_format    *f;
    char        *s;

    s = ft_strsub(str, i, ft_strlen(str) - i);
    if (!(f = (f_format*)(malloc(sizeof(f_format)))))
        return (0);
    //initialize(f);
    return set_format(f, s);

}
void     printf_len(char *str)
{
    int     i;
    int     len;
    int     f_len;

    f_len = 0;
    len = 0;
    while (str[i])
    {
        if (str[i] != '%' && !str[i])
        {
            write(1, str + i, 1);
            ++i;
        }
        //printf("%%d") --> %d
        else if (str[i] == '%' && str[i + 1] == '%')
        {
            ++i;
            write(1, str + i, 1);
        }
        else if (str[i] == '%')
        {
            f_len = format_len(str, i);
            len = len + f_len;
            i = i + f_len; 
        }
    }
    printf("length of string: %d\n", len);
}

void     ft_printf(char *str)
{
    int         len;

    printf_len(str); 
}

int main()
{
    ft_printf("hello");
    return (0);
}

