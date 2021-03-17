#include "bsq.h"

int is_space(char ch)
{
    if ((ch >= 9 && ch <= 13) || ch == ' ')
        return (1);
    return (0);
}

int non_printable(char *str)
{
    int i;

    i = 0;

    while (str[i])
    {
        if (str[i] < 32 || str[i] == 127)
            return (1);
        i++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int idx;

    idx = 0;
    while (str[idx])
        idx++;
    return (idx);
}

void ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
}

int numeric(char ch)
{
    if (ch >= '0' && ch <= '9')
        return (1);
    return (0);
}
