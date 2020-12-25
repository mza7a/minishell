/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 05:09:56 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 01:11:25 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*res;
	size_t		i;
	size_t		start;
	size_t		finish;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	finish = ft_strlen(s);
	while (ft_isspace(s[start]))
		start++;
	while (finish && ft_isspace(s[finish - 1]))
		finish--;
	if ((res = ft_strnew((finish > start) ? (finish - start) : 0)))
	{
		while (start < finish)
			res[i++] = s[start++];
		res[i] = '\0';
	}
	return (res);
}
