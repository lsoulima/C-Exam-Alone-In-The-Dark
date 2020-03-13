#include <unistd.h>

static int	match(char a, char b)
{
	return ((a == '[' && b == ']') || (a == '{' && b == '}') \
			|| (a == '(' && b == ')'));
}

static int	check(char *s)
{
	int		i = 0, top = 0, stack[4096];

	while (s[i])
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			stack[++top] = s[i];
		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			if (!match(stack[top--], s[i]))
				return (0);
		i++;
	}
	return (!top);
}

int			main(int ac, char **av)
{
	int		i = 0;
	if (ac == 1)
		write(1, "\n", 1);
	while (--ac)
	{
		if (check(av[++i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}