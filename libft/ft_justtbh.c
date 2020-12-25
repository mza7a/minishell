/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justtbh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 01:05:01 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 01:07:41 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_justtbh(char *res, char *str, int up, int low)
{
	int		i;

	i = 0;
	if (low >= up)
		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				res[i] = str[i] + 32;
			else
				res[i] = str[i];
			i++;
		}
	else
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				res[i] = str[i] - 32;
			else
				res[i] = str[i];
			i++;
		}
	res[i] = '\0';
	return (res);
}
