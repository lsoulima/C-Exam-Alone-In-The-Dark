/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 03:04:54 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/26 18:30:50 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_itoa_base(int val, int base)
{
	long n = (val < 0) ? -(long)val : val;
	int sign = (val < 0 && base == 10) ? 1 : 0;
	int size = sign ? 2 : 1;
	char *r;
	
	while (n /= base)
		size++;
	r = (char *)malloc(sizeof(char) * (size + 1));
	r[size] = '\0';
	n = (val < 0) ? -(long)val : val;
	if(sign)
		r[0] = '-';
	while (size-- > sign)
	{
		r[size] = (n % base < 10) ? (n % base + 48) : (n % base - 10 + 'A');
		n /= base;
	}
	return r;
}

#include <stdio.h>

int main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
}