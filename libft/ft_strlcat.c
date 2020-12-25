/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:19:12 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/05 18:30:38 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dest);
	lsrc = ft_strlen(src);
	i = 0;
	while (src[i] && (ldst + i + 1) < size)
	{
		dest[i + ldst] = src[i];
		i++;
	}
	dest[i + ldst] = '\0';
	if (ldst >= size)
		return (lsrc + size);
	else
		return (lsrc + ldst);
}
