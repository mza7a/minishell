/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 05:07:52 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 00:53:54 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**tab;
	int		flag;
	int		j;

	flag = 0;
	j = 0;
	i = -1;
	if (!(str) || !(tab = (char **)malloc(sizeof(char *) * ft_count_words(str,
						c) + 1)))
		return (NULL);
	while (str[++i])
	{
		if (str[i] != c && flag == 0)
		{
			tab[j] = (char *)malloc(sizeof(char) * ft_cchar(&str[i], c) + 1);
			tab[j] = ft_strccpy(tab[j], &str[i], c);
			flag = 1;
			j++;
		}
		else if (str[i] == c)
			flag = 0;
	}
	tab[j] = 0;
	return (tab);
}
