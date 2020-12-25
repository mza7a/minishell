/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 03:52:58 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/18 00:30:47 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*brute_force(char *cmd, char *path_env)
{
	char	**tab;
	char	*tmp;
	char	*tmp2;
	int		i;

	if (!(tab = ft_strsplit(path_env, ':')))
		return (NULL);
	i = -1;
	tmp = NULL;
	tmp2 = NULL;
	while (tab[++i])
	{
		tmp = ft_strjoin(tab[i], "/");
		tmp2 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (check_file(tmp2))
		{
			free_2d(&tab);
			return (tmp2);
		}
		free(tmp2);
	}
	free_2d(&tab);
	return (NULL);
}

void		real_exec(char **final, char *cmd, char **a_env)
{
	int		pid;

	if ((pid = fork()))
		wait(0);
	else
	{
		if (execve(cmd, final, a_env) == -1)
		{
			check_file_perm(final[0]);
			exit(0);
		}
	}
}

t_t			*exec_cmd(char *input, t_t *env)
{
	char	**final;
	char	**a_env;
	char	*full_path;

	final = NULL;
	full_path = NULL;
	if (!(final = ft_strsplitstr(input, " \t\n\r\a\"")))
		return (env);
	expansions(&final, env);
	if (!(check_builtins(final[0])))
	{
		if (!(check_file(final[0])) && final[0][0] != '.')
			full_path = brute_force(final[0], ft_lstsearch(env, "PATH"));
		else
			full_path = ft_strdup(final[0]);
		a_env = lst_array(env);
		real_exec(final, full_path, a_env);
		free(full_path);
		free_2d(&a_env);
	}
	else
		do_builtins(&final, &env, &input);
	free_2d(&final);
	return (env);
}
