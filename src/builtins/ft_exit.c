/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:26:46 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/12 05:18:48 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_exit(char ***final, t_t **env, char **input)
{
	free_2d(final);
	ft_strdel(input);
	free_list(env);
	exit(0);
}
