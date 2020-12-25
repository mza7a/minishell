/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:49:55 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/15 03:51:03 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *needl, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*needl)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < len)
	{
		if (str[pos] == needl[0])
		{
			i = 1;
			while (needl[i] != '\0' && str[pos + i] == needl[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (needl[i] == '\0')
				return ((char*)&str[pos]);
		}
		++pos;
	}
	return (0);
}
