/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:52:38 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/13 01:46:36 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		sos(t_t ***env, char *key, char *value)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup(key);
	tab[3] = NULL;
	if (value)
	{
		tab[2] = ft_strdup(value);
		ft_setenv(env, tab);
	}
	else
	{
		tab[2] = NULL;
		ft_unsetenv(env, tab);
	}
	free_2d(&tab);
}

int			check_for_errors(char *path)
{
	DIR		*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	else
	{
		if (errno == ENOENT)
			mini_printf("cd: No such file or directory: %s\n", path);
		else if (errno == EACCES)
			mini_printf("cd: Permission denied: %s\n", path);
		return (0);
	}
}

void		ft_cd(char **tab, t_t ***env)
{
	char	buff[MAX_SIZE];

	if (!tab[1])
	{
		if (!ft_lstsearch(**env, "HOME"))
			mini_printf("cd: HOME not set\n");
		else
			chdir(ft_lstsearch(**env, "HOME"));
	}
	else if (tab[1] && tab[1][0] == '-')
		chdir(ft_lstsearch(**env, "OLDPWD"));
	else
	{
		if (check_for_errors(tab[1]))
			chdir(tab[1]);
		else
			return ;
	}
	sos(env, "TEMP", ft_lstsearch(**env, "PWD"));
	sos(env, "PWD", getcwd(buff, MAX_SIZE));
	sos(env, "OLDPWD", ft_lstsearch(**env, "TEMP"));
	sos(env, "TEMP", NULL);
}
