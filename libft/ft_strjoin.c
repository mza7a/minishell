/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 05:01:29 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/06 05:14:31 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	int		size_c;
	char	*strc;

	if (s1 && s2)
	{
		size_s1 = ft_strlen(s1);
		size_s2 = ft_strlen(s2);
		size_c = size_s1 + size_s2;
		strc = (char *)ft_memalloc(sizeof(char) * (size_c + 1));
		if (strc == NULL)
			return (NULL);
		ft_strcat(strc, s1);
		ft_strcat(strc, s2);
		return (strc);
	}
	return (NULL);
}
