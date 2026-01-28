#include <stdio.h>
#include <stdlib.h>

static int safe(int *p, int c, int r)
{
    int i = 0;

    while (i < c)
    {
        if (p[i] == r || p[i] - r == i - c || p[i] - r == c - i)
            return (0);
        i++;
    }
    return (1);
}

static void solve(int *p, int c, int n)
{
    int r = 0;
    int i;

    if (c == n)
    {
        i = 0;
        while (i < n)
        {
            if (i)
                printf(" ");
            printf("%d", p[i]);
            i++;
        }
        printf("\n");
        return ;
    }
    while (r < n)
    {
        if (safe(p, c, r))
        {
            p[c] = r;
            solve(p, c + 1, n);
        }
        r++;
    }
}

int main (int ac, char *av[])
{
    int *p;
    int n;

    if (ac != 2)
        return (1);
    n = atoi(av[1]);
    if (n < 0)
        return (0);
    p = malloc(sizeof(int) * n);
    if (!p)
        return (1);
    solve(p, 0, n);
    return (free(p), 0);
}
