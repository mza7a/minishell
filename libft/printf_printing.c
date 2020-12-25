/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:53:42 by hmzah             #+#    #+#             */
/*   Updated: 2019/11/23 08:24:00 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_intlen(int x)
{
	int		i;

	i = 0;
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	return (i);
}

void		printf_space_int(int x, int y)
{
	int		space_num;

	space_num = x - ft_intlen(y);
	while (space_num > 0)
	{
		write(1, " ", 1);
		space_num--;
	}
	ft_putnbr(y);
}

void		printf_space_str(int i, char *str)
{
	int		space_str;

	space_str = i - ft_strlen(str);
	while (space_str > 0)
	{
		write(1, " ", 1);
		space_str--;
	}
	ft_putstr(str);
}
