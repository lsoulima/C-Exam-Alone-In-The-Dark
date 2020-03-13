/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulima <lsoulima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 21:36:48 by lsoulima          #+#    #+#             */
/*   Updated: 2020/02/19 01:27:10 by lsoulima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int		ft_strlen(char *s)
{
	return(*s ? 1 + ft_strlen(s+1) : 0);
}

void	biggest_pal(char *s)
{
	int		i = 0, maxlen = 1 , len = ft_strlen(s), start = len - 1 , low, high;

	while (++i < len)
	{
		low = i - 1;
		high = i + 1;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 >= maxlen)
			{
				start = low;
				maxlen = high - low + 1;
			}
			high++;
			low--;
		}
		low = i - 1;
		high = i;
		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 >= maxlen)
			{
				start = low;
				maxlen = high - low + 1;
			}
			high++;
			low--;
		}
	}
	write(1, &s[start], maxlen);	
}

int		main(int ac, char **av)
{
	if(ac==2)
		biggest_pal(av[1]);
	write(1,"\n",1);
	
	return 0;
}
