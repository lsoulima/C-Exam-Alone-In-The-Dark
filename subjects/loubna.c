/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loubna.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 20:19:30 by lsoulima          #+#    #+#             */
/*   Updated: 2020/03/03 23:56:59 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


                                    //----------------\\/
                                    //   biggest_pal  \\/
                                    //----------------\\/

// int ft_len(char *s)
// {
//     return(*s ? 1+ft_len(s+1) : 0);
// }

// void big(char *s)
// {
//     int i=0, maxlen=1, len=ft_len(s), start=len-1, high, low;
//     while(++i < len)
//     {
//         low=i-1;
//         high=i+1;
//         while(low >=0 && high < len && s[low] == s[high])
//         {
//             if(high - low +1 >= maxlen)
//             {
//                 start = low;
//                 maxlen = high -low +1;
//             }
//             high++;
//             low--;
//         }
//         low=i-1;
//         high=i+1;
//         while(low >=0 && high < len && s[low] == s[high])
//         {
//             if(high - low +1 >= maxlen)
//             {
//                 start = low;
//                 maxlen = high -low +1;
//             }
//             high++;
//             low--;
//         }
//     }
//     write(1, &s[start], maxlen);
// }

// int main(int ac, char **av)
// {
//     if(ac == 2)
//         big(av[1]);
//     write(1, "\n", 1);
// }

                                    //----------------\\/
                                    //     rpncalc    \\/
                                    //----------------\\/

int main(int ac,char **av)
{
    t_stack *stack = NULL;
    char *s = av[1];
    if(ac == 2)
    {
        while((s= skip_space(s)) && *s)
        {
            if(isinstr(*s, "+-*/%") && (s[1] == ' ' || s[1] == '\0'))
            {
                if(stack && stack->next && (!isinstr(*s, "/%") || stack->val != 0)
                {
                    stack->next->val = do_op(stack->next->val, stack->val, *s);
                    stack = stack->next;
                }
                else 
                    return(printf("Error\n"));
            }
            else
                add_to_stack(&stack, atoi(s));
            s = skip_until_space(s);
        }
        !stack || stack->next ? printf("Error") : printf("%d", stack->val);
    }
    printf("\n");
}


                                    //----------------\\/
                                    //   check_mate   \\/
                                    //----------------\\/



                                    //----------------\\/
                                    //  print_memory  \\/
                                    //----------------\\/

// void putnbr_hex(int octet, int rem)
// {
//     char const *b = "0123456789abcdef";
//     rem > 1 ? putnbr_hex(octet >> 4, rem - 1) : 0;
//     write(1, b + (octet % 16), 1);
// }

// void putchar_hex(unsigned char const *s)
// {
//     char const c = *s;
//     ' ' <= c && c <= '~' ? write(1, s, 1) : write(1, ".", 1);
// }

// void	p_mem(const void *addr, size_t size)
// {
//     unsigned char const *ptr = addr;
//     size_t i = 0, a;
//     while(i < size)
//     {
//         a = 0;
//         while(a < 16 && a + i < size)
//         {
//             putnbr_hex(*(ptr+a+i), 2);
//             a%2 ? write(1, " ", 1) : 0;
//             a++;
//         }
//         while(a < 16)
//         {
//             write(1, "  ", 2);
//             a%2 ? write(1, " ", 1) : 0;
//             a++;
//         }
//         a = 0;
//         while(a < 16 && a + i < size)
//         {
//             putchar_hex(ptr+a+i);
//             a++;
//         }
//         i += 16;
//         write(1, "\n", 1);
//     }
// }
// int	main(void)
// {
// 	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
// 	p_mem(tab, sizeof(tab));
// }

                                    //----------------\\/
                                    //    brackets    \\/
                                    //----------------\\/
// int match(char a, char b)
// {
//     return((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')'));
// }

// int check(char *s)
// {
//     int i = 0, top = 0, stack[4096];

//     while(s[i])
//     {  
//         if(s[i] == '[' || s[i] == '{' || s[i] == '(')
//             stack[++top] = s[i];
//         if(s[i] == ']' || s[i] == '}' || s[i] == ')')
//             if(!match(stack[top--], s[i]))
//                 return 0;
//         i++;
//     }
//     return(!top);
// }

// int main(int ac, char **av)
// {
//     int i = 0;
//     if(ac == 1)
//         write(1, "\n", 1);
//     while(--ac)
//     {
//         if(check(av[++i]))
//             write(1, "OK\n", 3);
//         else
//             write(1,"Error\n", 6);
//     }
//     return 0;
// }

                                    //----------------\\/
                                    //    brainfuck   \\/
                                    //----------------\\/

// char *match(char *s, int way)
// {
//     int i = 0;
//     while(1)
//     {    
//         *s == '[' ? i++ : 0;
//         *s == ']' ? i-- : 0;
//         if(i == 0)
//             return(s);
//         s += way;
//     }
//     return(NULL);
// }

// void brain(char *s)
// {
//     int i = 0;
//     char *bf = malloc(sizeof(char) * 4096);
//     while(i < 4096)
//         bf[i++] = 0;
//     while(*s)
//     {
//         *s == '>' ? bf++ : 0;
//         *s == '<' ? bf-- : 0;
//         *s == '+' ? (*bf)++ : 0;
//         *s == '-' ? (*bf)-- : 0;
//         *s == '.' ? write(1, &*bf, 1): 0;
//         *s == '[' && *bf == 0 ? s = match(s, 1) : 0;
//         *s == ']' && *bf != 0 ? s = match(s, -1) : 0;
//         s++;
//     }
// }

// int main(int ac, char **av)
// {
//     ac == 2 ? brain(av[1]) : write(1, "\n", 1);
// }

                                    //----------------\\/
                                    //      moment    \\/
                                    //----------------\\/

// char *ft_itoa(unsigned int n)
// {
//     int i = 0 , j = 0;
//     char rev[11];
//     while(n > 9)
//     {
//         rev[i++] = n % 10 + 48;
//         n /= 10;
//     }
//     rev[i++] = n % 10 + 48;
//     char *r = malloc(sizeof(char) * i);
//     while(i--)
//         r[i] = rev[j++];
//     return r;
// }

// char *merg(unsigned int d, char *s2)
// {
//     int i = 0;
//     char *r = malloc(sizeof(char) * 4096);
//     char *s1 = ft_itoa(d);
//     while(*s1)
//         r[i++] = *s1++;
//     while(*s2)
//         r[i++] = *s2++;
//     r[i] = '\0';
//     return r;
// }

// char    *moment(unsigned int d)
// {
//     char *r = malloc(sizeof(char) * 4096);
//     if(d < 60)
//         r = merg(d, d == 1 ? " second ago." : " seconds ago.");
//     else if(d < 60*60)
//         r = merg(d / 60, d / 60 == 1 ? " minute ago." : " minutes ago.");
//     else if(d < 60*60*24)
//         r = merg(d / (60*60), d / (60*60) == 1 ? " hour ago." : " hours ago.");
//     else if(d < 60*60*24*30)
//         r = merg(d / (60*60*24), d / (60*60*24) == 1 ? " day ago." : " days ago.");
//     else
//         r = merg(d / (60*60*24*30), d / (60*60*24*30) == 1 ? " month ago." : " months ago.");
//     return r;
// }

// int main(int ac, char **av)
// {
// 	if(ac==2)
// 	{
// 		printf("%s", moment(atoi(av[1])));
// 	}
// 	printf("\n");
// }

                                    //----------------\\/
                                    //     fprime     \\/
                                    //----------------\\/

// void fprime(int n)
// {
//     int i = 1;
//     n == 1 ? printf("1") : 0;
//     while(++i <= n)
//     {
//         if(n % i == 0)
//         {
//             n /= i;
//             printf("%d", i);
//             n > 1 ? printf("*") : 0;
//             i--;
//         }
//     }
// }

// int main(int ac, char**av)
// {
//     if(ac==2)
//         fprime(atoi(av[1]));
//     printf("\n");
// }
                                    //----------------\\/
                                    //    itoa_base   \\/
                                    //----------------\\/

// char *ft_itoa_base(int val, int base)
// {
//     long n = val < 0 ? -(long)val : val;
//     int sign = val < 0 ? 1 : 0;
//     int size = sign ? 2 : 1;

//     while(n /= base)
//         size++;
//     char *r = malloc(sizeof(char) * (size+1));
//     r[size] = '\0';
//     sign ? r[0] = '-' : 0;
//     n = val < 0 ? -(long)val : val;
//     while(size-- > sign)
//     {
//         r[size] = n%base < 10 ? n%base + 48 : n%base+55;
//         n /= base;
//     }
//     return r;
// }
// int main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
// }

                                    //----------------\\/
                                    //    rev_wstr    \\/
                                    //----------------\\/

// void rev(char *s, int index)
// {
//     int c=0;
//     for(;s[c] != ' ' && s[c] != '\0' && s[c] != '\t';c++);
//     for(;s[c] == ' ' || s[c] == '\t';c++);
//     s[c] ? rev(s+c, index+1) : 0;
//     while(*s && *s != ' ' && *s != '\t')
//         write(1, s++, 1);
//     index > 0 ? write(1, " ", 1) : 0;

// }

// int main(int ac, char **av)
// {
//     if(ac==2)
//         rev(av[1], 0);
//     write(1,"\n", 1);
// }

                                    //----------------\\/
                                    //    rostring    \\/
                                    //----------------\\/

// void rot(char *s)
// {
//     int i = 0;
//     while(s[i] && s[i] < 33)
//         i++;
//     while(s[i] && s[i] >= 33)
//         i++;
//     while(s[i] && s[i] < 33)
//         i++;
//     while(s[i])
//     {
//         while(s[i] && s[i] >= 33)
//             write(1,&s[i++],1);
//         while(s[i] && s[i] < 33)
//             i++;
//         write(1," ",1);
//     }
//     i = 0;
//     while(s[i] && s[i] < 33)
//         i++;
//     while(s[i] && s[i] >= 33)
//         write(1,&s[i++],1);
// }

// int main(int ac, char **av)
// {
//     if(ac > 1)
//         rot(av[1]);
//     write(1, "\n", 1);
// }

                                    //-----------------\\/
                                    //    flood_fill   \\/
                                    //-----------------\\/

// #include "t_point.h"

// void fill(char **tab, int x, int y, int f, t_point size)
// {
//     if(x < 0 || y < 0 || x >= size.x || y >= size.y || f != tab[y][x])
//         return;
//     tab[y][x] = 'F';
//     fill(tab, x-1, y, f, size);
//     fill(tab, x+1, y, f, size);
//     fill(tab, x, y-1, f, size);
//     fill(tab, x, y+1, f, size);
// }

// void  flood_fill(char **tab, t_point size, t_point begin)
// {
//     char f = tab[begin.y][begin.x];
//     fill(tab, begin.x, begin.y, f, size);
// }

