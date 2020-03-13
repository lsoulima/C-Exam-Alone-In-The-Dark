/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:08:25 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/26 17:01:56 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>

char *brackets(char *s, int way)
{
    int i = 0;
    while(1)
    {
        (*s == '[')? i++ : 0;
        (*s == ']')? i--: 0;
        if(i == 0)
            return(s);
        s = s + way;
    }
    return(NULL);
}
void brainfuck(char *s)
{
    int i = 0;
    char *buff = (char *)malloc(sizeof(*buff) * 4096);
    while (4096 > i)
        buff[i++] = 0;
    while(*s)
    {
        (*s == '<')?  buff-- : 0;
        (*s == '>')? buff++ : 0;
        (*s == '+')? (*buff)++: 0;
        (*s == '-')? (*buff)--: 0;
        (*s == '.')? write(1,&*buff,1): 0;
        (*s == '[' && *buff == 0)? s = brackets(s,1): 0;
        (*s == ']' && *buff != 0)? s = brackets(s, -1): 0;
        s++;
    }
}
int main(int ac, char **av)
{
    ac == 2? brainfuck(av[1]) : write(1,"\n",1);
}
