/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:20:41 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/27 13:38:09 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
​
void	rot(char *s)
{
    int i = 0;
    while(s[i] && s[i] < 33)
        i++;
    while(s[i] && s[i] >= 33)
        i++;
    while(s[i] && s[i] < 33)
        i++;
    while(s[i])
    {
        while(s[i] && s[i] >= 33)
            write(1, &s[i++], 1);
        while(s[i] && s[i] < 33)
            i++;
        write(1, " ", 1);
    }
    i = 0;
    while(s[i] && s[i] < 33)
        i++;
    while(s[i] && s[i] >= 33)
        write(1, &s[i++], 1);
}

int		main(int ac, char **av)
{
    if(ac > 1)
        rot(av[1]);
    write(1, "\n", 1);
}