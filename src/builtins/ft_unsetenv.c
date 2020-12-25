/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 01:38:32 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/12 05:19:31 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_node(t_t ****env, char *key)
{
	t_t *fresh;
	t_t	*prev;

	fresh = ***env;
	if (fresh != NULL && !ft_strcmp(fresh->key, key))
	{
		free(fresh->key);
		free(fresh->value);
		***env = fresh->next;
		free(fresh);
		return ;
	}
	while (fresh != NULL && ft_strcmp(fresh->key, key))
	{
		prev = fresh;
		fresh = fresh->next;
	}
	if (fresh == NULL)
		return ;
	prev->next = fresh->next;
	free(fresh->key);
	free(fresh->value);
	free(fresh);
}

void	ft_unsetenv(t_t ***env, char **final)
{
	int	i;

	i = 1;
	while (final[i])
		i++;
	if ((i - 1) != 1)
	{
		mini_printf("Too few, many arguments.\n");
		return ;
	}
	delete_node(&env, final[1]);
}
