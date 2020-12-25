/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 03:08:56 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/12 23:10:16 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		tilda(char **tab, t_t *env)
{
	char	*home;
	char	*res;

	home = NULL;
	res = NULL;
	home = ft_lstsearch(env, "HOME");
	res = ft_strjoin(home, &(*tab)[1]);
	free(*tab);
	*tab = ft_strdup(res);
	free(res);
}

int			check_symb(char *str, int index)
{
	while (str[index] && ft_isalnum(str[index]))
		index++;
	return (index);
}

void		do_dollar(char *tab, t_t *env, char **new_str, int i)
{
	char	*tmp;
	char	*var;
	char	*teemp;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '$' && tab[i + 1])
		{
			var = ft_strsub(tab, i, check_symb(tab, i + 1) - i);
			if (ft_lstsearch(env, ft_strchr(var, '$') + 1))
				tmp = ft_strdup(ft_lstsearch(env, ft_strchr(var, '$') + 1));
			else
				tmp = ft_strdup("");
		}
		else
			tmp = ft_strsub(tab, i, check_symb(tab, i + 1) - i);
		teemp = ft_strdup(*new_str);
		ft_strdel(&(*new_str));
		(*new_str) = ft_strjoin(teemp, tmp);
		ft_strdel(&tmp);
		ft_strdel(&teemp);
		i = check_symb(tab, i + 1);
	}
}

void		expansions(char ***tab, t_t *env)
{
	int		i;
	char	*new_str;

	i = 0;
	while ((*tab)[i] != NULL)
	{
		if ((*tab)[i][0] == '~' && ((*tab)[i][1] == '/' || !(*tab)[i][1]))
		{
			tilda(&(*tab)[i], env);
		}
		else
		{
			new_str = ft_strdup("");
			do_dollar((*tab)[i], env, &new_str, 0);
			ft_strdel(&(*tab)[i]);
			(*tab)[i] = ft_strdup(new_str);
			ft_strdel(&new_str);
		}
		i++;
	}
}
