/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpncalc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:34:50 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/23 18:35:42 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct   s_stack
{
    int                 val;
    struct s_stack      *next;
}               t_stack;

char *skip_space(char *s)
{
    while (*s == ' ')
        s++;
    return (s);
}

char *skip_until_space(char *s)
{
    while (*s && *s != ' ')
        s++;
    return (s);
}

int isinstr(char c, const char *str)
{
    while (*str)
        if(c == *str++)
            return (1);
    return (0);
}

void add_to_stack(t_stack **lst, int val)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    new->val = val;
    new->next = *lst;
    *lst = new;
}

int do_op(int op1, int op2, char opr)
{
    int r = 0;

    opr == '+' ? r = op1 + op2 : 0;
    opr == '-' ? r = op1 - op2 : 0;
    opr == '*' ? r = op1 * op2 : 0;
    opr == '/' ? r = op1 / op2 : 0;
    opr == '%' ? r = op1 % op2 : 0;
    return (r);
}

int main(int ac, char **av)
{
    t_stack *stack = NULL;
    char *s = av[1];
    if (ac == 2)
    {
       
        while ((s = skip_space(s)) && *s)
        {
            if (isinstr(*s, "+-*/%") && (s[1] == ' ' || s[1] == '\0'))
            {
                if (stack && stack->next && (!isinstr(*s, "/%") || stack->val != 0))
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