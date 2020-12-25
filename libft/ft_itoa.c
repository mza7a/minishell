/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 04:57:27 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 01:10:18 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		int_size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	int_size = ft_intcount(n);
	if (n <= 0)
		int_size = int_size + 1;
	if (!(str = (char *)malloc(sizeof(char) * int_size + 1)))
		return (NULL);
	if (n <= 0)
	{
		i = 1;
		str[0] = n == 0 ? '0' : '-';
		n = -n;
	}
	str[int_size] = '\0';
	while (i <= --int_size)
	{
		str[int_size] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
