#include <stdio.h>
int main(int ac, char **av)
{
    int i = 0;
    while(av[1][i])
        i++;
    printf("%d\n", i);
}