/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:34:50 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/26 15:21:36 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char *ft_itoa(unsigned int n)
{
	int i = 0, j = 0;
	char r[11];
	while (n > 9)
	{
		r[i++] = n % 10 + 48;
		n /= 10;
	}
	r[i++] = n % 10 + 48;
	char *res = malloc(sizeof(char) * i);
	while (i--)
		res[i] = r[j++];
	return res;
}

char *merg(unsigned int d, char *s2)
{
	char *r = malloc(sizeof(char) * 4096);
	int i = 0;
	char *s1 = ft_itoa(d);
	while (*s1)
			r[i++] = *s1++;
	while (*s2)
		r[i++] = *s2++;
	r[i] = '\0';
	return r;
}

char *moment(unsigned int d)
{
	char *r = malloc(sizeof(char) * 4096);
	if(d < 60)
		r = merg(d, d == 1 ? " second ago." : " seconds ago.");
	else if(d < 60*60)
		r = merg(d / (60), d / 60 == 1 ? " minute ago." : " minute ago.");
	else if(d < 60*60*24)
		r = merg(d / (60*60),  (d / (60*60) == 1) ?  " hour ago." : " hours ago.");
	else if(d < 60*60*24*30)
		r =  merg(d / (60*60*24), d / (60*60*24) == 1 ? " day ago." : " days ago.");
	else 
		r = merg(d / (60*60*24*30), d / (60*60*24*30) == 1 ? " month ago." : " months ago.");
	return r;
}

#include <stdio.h>
int main(int ac, char **av)
{
	if(ac==2)
	{
		printf("%s", moment(atoi(av[1])));
	}
	printf("\n");
}
