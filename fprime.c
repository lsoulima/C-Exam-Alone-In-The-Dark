#include <stdio.h>
#include <stdlib.h>

void	fprime(int	nbr)
{
	int		i = 1;
	nbr == 1 ? printf("1") : 0;
	while (++i <= nbr)
	{
		if (nbr % i == 0)
		{
			nbr /= i;
			printf("%d", i);
			nbr > 1 ? printf("*") : 0;
			i--;
		}
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");	
	return (0);
}