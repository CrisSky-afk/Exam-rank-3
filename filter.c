#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int match(char *a, char *b, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        if (a[i] != b[i])
            return (0);
        i++;
    }
    return (1);
}

int main (int ac, char *av[])
{
    char buffer[4096];
    char *pend;
    size_t cvp = 0, size;
    ssize_t r;

    if (ac != 2 || !av[1] || !av[1][0])
        return (1);
    size = strlen(av[1]);
    pend = malloc(size);
    if (!pend)
        return (fprintf(stderr, "Error: "), perror("malloc"), 1);
    while ((r = read(0, buffer, sizeof(buffer))) > 0)
    {
        size_t i = 0;
        while (i < (size_t)r)
        {
            pend[cvp++] = buffer[i++];
            if (cvp == size)
            {
                if (match(pend, av[1], size))
                {
                    size_t k = 0;
                    while (k++ < size)
                        write (1, "*", 1);
                    cvp = 0;
                }
                else
                {
                    write (1, pend, 1);
                    memmove(pend, pend + 1, --cvp);
                }
            }
        }
    }
    if (r < 0)
        return (fprintf(stderr, "Error: "), perror("read"), 1);
    if (cvp)
        write (1, pend, cvp);
    return (free(pend), 0);
}