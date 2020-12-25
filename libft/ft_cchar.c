/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:47:56 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 00:53:34 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_cchar(char const *str, char c)
{
	int		count_char;

	count_char = 0;
	while (str[count_char] != c && str[count_char])
	{
		count_char++;
	}
	return (count_char);
}
