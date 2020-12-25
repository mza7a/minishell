/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_prime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:25:23 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/16 00:42:55 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_add_prime(int nb)
{
	unsigned int	min_nb;
	unsigned int	res;

	min_nb = 3;
	res = 2;
	if (nb < 0)
	{
		ft_printf_beta("Invalid number the program will now exit...\n");
		return (0);
	}
	while (min_nb <= (unsigned int)nb)
	{
		res += ft_is_prime(min_nb);
		min_nb++;
	}
	ft_putnbr(res);
	return (0);
}
