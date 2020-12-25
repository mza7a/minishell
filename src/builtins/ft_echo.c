/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:44:36 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/12 05:18:39 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_echo(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		mini_printf("%s", str[i]);
		if (str[i + 1] != NULL)
			mini_printf(" ");
		i++;
	}
	mini_printf("\n");
}
