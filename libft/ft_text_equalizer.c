/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_equalizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 01:07:13 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 01:06:45 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_text_equalizer(char *str)
{
	int		count_up;
	int		count_low;
	char	*res;
	int		i;

	count_up = 0;
	count_low = 0;
	i = 0;
	res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			count_low++;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			count_up++;
		i++;
	}
	ft_justtbh(res, str, count_up, count_low);
}
