/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:51:10 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/27 13:20:07 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	rev_wstr(char *s, int index)
{
	int c = 0;

	for(;s[c] != ' ' && s[c] != '\t' && s[c] != '\0';c++);
	for(;s[c] == ' ' || s[c] == '\t' ;c++);
	s[c]?rev_wstr(s+c,index+1):0;
	while(*s && *s != ' ' && *s != '\t')
		write(1,s++,1);
	index>0?write(1," ",1):0;

}

int		main(int ac, char **av)
{
	if(ac == 2)
		rev_wstr(av[1], 0);
	write(1, "\n", 1);
	return 0;
}
