#include <unistd.h>
#include <stdlib.h>

static void swap(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

static void permute(char *s, int pos, int len)
{
    int i;

    if (pos == len)
    {
        write (1, s, len);
        write (1, "\n", 1);
        return ;
    }
    i = pos;
    while (i < len)
    {
        swap(&s[pos], s[i]);
        permute(s, pos + 1, len);
        swap(&s[pos], s[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    int len = 0;
    char *s;

    if (ac != 2)
        return (1);

    while (av[1][len])
        len++;

    s = malloc(len + 1);
    if (!s)
        return (1);

    len = 0;
    while (av[1][len])
    {
        s[len] = av[1][len];
        len++;
    }
    s[len] = 0;

    permute(s, 0, len);
    free(s);
    return (0);
}
