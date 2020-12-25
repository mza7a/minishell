/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:22:10 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/17 23:27:35 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		free_list(t_t **env)
{
	t_t		*fresh;

	while ((*env) != NULL)
	{
		fresh = *env;
		(*env) = (*env)->next;
		ft_strdel(&fresh->key);
		ft_strdel(&fresh->value);
		free(fresh);
	}
}

char		*ft_lstsearch(t_t *env, char *to_search)
{
	t_t		*fresh;

	fresh = env;
	while (fresh != NULL)
	{
		if (!(ft_strcmp(fresh->key, to_search)))
			return (fresh->value);
		fresh = fresh->next;
	}
	return (NULL);
}

int			lst_size(t_t *env)
{
	int		i;
	t_t		*fresh;

	i = 0;
	fresh = env;
	while (fresh != NULL)
	{
		i++;
		fresh = fresh->next;
	}
	return (i);
}

void		print_lst(t_t *env)
{
	t_t *fresh;

	fresh = env;
	while (fresh != NULL)
	{
		mini_printf("%s=%s\n", fresh->key, fresh->value);
		fresh = fresh->next;
	}
}

char		**lst_array(t_t *env)
{
	t_t		*fresh;
	char	**tab;
	char	*join;
	char	*join2;
	int		i;

	fresh = env;
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * (lst_size(env) + 1))))
		return (NULL);
	i = -1;
	while (fresh != NULL)
	{
		join = ft_strjoin("=", fresh->value);
		join2 = ft_strjoin(fresh->key, join);
		free(join);
		tab[++i] = ft_strdup(join2);
		free(join2);
		fresh = fresh->next;
	}
	tab[lst_size(env)] = NULL;
	return (tab);
}
