#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
	if (!s[i])
	{
		if (rm == min && valid(s))
		{
			write(1, s, strlen(s));
			write(1, "\n", 1);
		}
		return;
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

int main(int ac, char **av)
{
	char *s;
	int min;

	if (ac != 2)
		return (1);
	s = strdup(av[1]);
	if (!s)
		return (1);
	min = min_rm(s);
	bt(s, 0, 0, min);
	return (free(s), 0);
}
