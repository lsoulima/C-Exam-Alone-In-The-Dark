/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:58:54 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/19 00:56:22 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void putnbr_hex(int octet, int rem)
{
	char const *base = "0123456789abcdef";
	rem > 1 ? putnbr_hex(octet >> 4, rem -1) : 0;
	write(1,base + (octet % 16),1);
}

void putchar_hex(unsigned char const *ptr)
{
	char const c = *ptr;
	(' ' <= c && c <= '~') ? write(1,ptr,1) : write(1,".",1);
}

void	p_mem(const void *addr, size_t size)
{
	unsigned char const *ptr = addr;
	size_t i = 0, a;
	while(i < size)
	{
		a = 0;
		while(a < 16 && a + i < size)
		{
			putnbr_hex(*(ptr + a + i), 2);
			a % 2 ? write(1," ",1) : 0;
			a++;
		}
		while(a < 16)
		{
			write(1,"  ",2);
			a % 2 ? write(1," ",1) : 0;
			a++;
		}
		a = 0;
		while(a < 16 && a + i < size)
		{
			putchar_hex(ptr + a + i);
			a++;
		}
		write(1,"\n",1);
		i += 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	p_mem(tab, sizeof(tab));
}
