/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:19:42 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/13 02:37:15 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "setenv"))
		return (1);
	else if (!ft_strcmp(cmd, "unsetenv"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
		return (1);
	else if (!ft_strcmp(cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

void	do_builtins(char ***final, t_t **env, char **input)
{
	if (!ft_strcmp((*final)[0], "setenv"))
		ft_setenv(&env, *final);
	if (!ft_strcmp((*final)[0], "unsetenv"))
		ft_unsetenv(&env, *final);
	if (!ft_strcmp((*final)[0], "env"))
		ft_env(*env);
	if (!ft_strcmp((*final)[0], "echo"))
		ft_echo(*final);
	if (!ft_strcmp((*final)[0], "cd"))
		ft_cd(*final, &env);
	if (!ft_strcmp((*final)[0], "exit"))
		ft_exit(final, env, input);
}
