/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thething.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 04:01:16 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/14 21:09:25 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_find_multip(unsigned int i, int n)
{
	unsigned int	x;
	unsigned int	y;
	int				**t;
	unsigned int	count;

	t = (int **)malloc(sizeof(int) * (i * 2));
	x = -1;
	count = 0;
	while (++x < i)
	{
		y = -1;
		t[x] = (int *)malloc(sizeof(int) * i);
		while (++y < i)
			t[x][y] = (x + 1) * (y + 1);
	}
	x = -1;
	while (++x < i)
	{
		y = -1;
		while (++y < i)
			if (t[x][y] == n)
				count++;
	}
	return (count);
}
