/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:11:53 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/13 00:02:07 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_encrypt(char *str)
{
	unsigned int	i;
	char			*res;

	i = ft_strlen(str);
	res = (char*)malloc(sizeof(char) * i);
	i = 0;
	if (!res)
		return (NULL);
	while (str[i])
	{
		if ((str[i] >= 'x' && str[i] <= 'z') ||
				(str[i] >= 'X' && str[i] <= 'Z'))
			res[i] = str[i] - 23;
		else if ((str[i] >= 'a' && str[i] <= 'c') ||
				(str[i] >= 'A' && str[i] <= 'C'))
			res[i] = str[i] + 23;
		else if ((str[i] >= 'd' && str[i] <= 'w') ||
				(str[i] >= 'D' && str[i] <= 'W'))
			res[i] = str[i] - 3;
		i++;
	}
	return (res);
}
