/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 03:37:27 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/12 05:22:21 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_lsta(t_t ****env, char *key, char *value)
{
	t_t		*new_node;
	t_t		*last;

	new_node = (t_t *)malloc(sizeof(t_t));
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	last = ***env;
	if (***env == NULL)
	{
		***env = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}

void		ft_lstreplace(t_t ****env, char *key, char *value)
{
	t_t		*fresh;

	fresh = ***env;
	while (fresh != NULL)
	{
		if (!ft_strcmp(fresh->key, key))
		{
			free(fresh->value);
			fresh->value = ft_strdup(value);
		}
		fresh = fresh->next;
	}
}

void		ft_setenv(t_t ***env, char **final)
{
	int		i;

	i = 1;
	while (final[i])
		i++;
	if ((i - 1) != 2)
	{
		mini_printf("Too few, many arguments.\n");
		return ;
	}
	if (!ft_lstsearch(**env, final[1]))
		ft_lsta(&env, final[1], final[2]);
	else
		ft_lstreplace(&env, final[1], final[2]);
}
