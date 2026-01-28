#include <stdio.h>

static int valid(char *s)
{
    int i = 0, b = 0;

    while (s[i])
    {
        if (s[i] == '(')
            b++;
        else if (s[i] == ')')
        {
            if (!b)
                return (0);
            b--;
        }
        i++;
    }
    return (!b);
}

static int min_rm(char *s)
{
    int i = 0, o = 0, r = 0;

    while (s[i])
    {
        if (s[i] == '(')
            o++;
        else if (s[i] == ')')
        {
            if (o)
                o--;
            else
                r++;
        }
        i++;
    }
    return (r + o);
}

static void bt(char *s, int i, int rm, int min)
{
    int len = 0;
    while (s[len])
        len++;
    if (!s[i])
    {
        if (rm == min && valid(s))
            puts(s);
        return ;
    }
    if (s[i] == '(' || s[i] == ')')
    {
        char c = s[i];
        s[i] = ' ';
        bt(s, i + 1, rm + 1, min);
        s[i] = c;
    }
    bt(s, i + 1, rm, min);
}

// int main (int ac, char *av[])
// {
//     char s[4096];
//     int min, i = 0;

//     if (ac != 2)
//         return (1);
//     while (av[1][i])
//     {
//         s[i] = av[1][i];
//         i++;
//     }
//     s[i] = 0;
//     min = min_rm(s);
//     bt(s, 0, 0, min);
//     return (0);
// }

int main (int ac, char *av[])
{
    char s[4096];
    int i = 0, min;

    if (ac != 2)
        return (1);
    while (av[1][i])
    {
        s[i] = av[1][i];
        i++;
    }
    min = min_rm(s);
    bt(s, 0, 0, min);
    return (0);
}