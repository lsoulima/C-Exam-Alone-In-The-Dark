/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:57:16 by lsoulima          #+#    #+#             */
/*   Updated: 2020/03/02 22:16:00 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define sign(v) ((v) >= 0 ? 1 : -1)

typedef struct s_piece
{
    int x, y, type;
    struct s_piece *next;
} t_piece;

int isinstr(char c, const char *s)
{
    while (*s)
        if (c == *s++)
            return (1);
    return (0);
}

void add_piece(t_piece **p, int x, int y, int type)
{
    t_piece *ptr = malloc(sizeof(t_piece));
    *ptr = (t_piece){x, y, type, *p};
    *p = ptr;
}

int chess_mate(t_piece p, t_piece king, char **av, int size)
{
    int x = king.x - p.x ? sign(king.x - p.x) : 0;
    int y = king.y - p.y ? sign(king.y - p.y) : 0;
    if ((p.type == 'B' || p.type == 'P') && (!y || !x))
        return (0);
    if (p.type == 'R' && y && x)
        return (0);
    p = (t_piece){p.x + x, p.y + y, p.type, NULL};
    while (p.x >= 0 && p.x < size && p.y >= 0 && p.y < size)
    {
        if (av[p.y][p.x] == 'K')
            return (1);
        if (p.type == 'P' || isinstr(av[p.y][p.x], "QRBP"))
            break;
        p = (t_piece){p.x + x, p.y + y, p.type, NULL};
    }
    return (0);
}

int main(int ac, char **av)
{
    t_piece king, *p = NULL;
    int y = -1, x;
    ac--, av++;
    if (ac)
    {
        while (++y < ac)
        {
            x = 0;
            while (av[y][x])
            {
                if (isinstr(av[y][x], "QRBP"))
                    add_piece(&p, x, y, av[y][x]);
                else if (av[y][x] == 'K')
                    king = (t_piece){x, y, 'K', NULL};
                x++;
            }
        }
        while (p)
        {
            if (chess_mate(*p, king, av, ac))
                return (write(1, "Success\n", 8) * 0);
            p = p->next;
        }
        return (write(1, "Fail\n", 5));
    }
    return (write(1, "\n", 1));
}