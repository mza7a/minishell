/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 03:37:20 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/18 00:25:31 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			g_check;
t_t			*g_env;

t_t			*init_env(char **env)
{
	int		i;
	t_t		*actual_env;
	t_t		*fresh;

	fresh = NULL;
	actual_env = NULL;
	i = -1;
	if (!(actual_env = (t_t *)malloc(sizeof(t_t))) || env[0] == NULL)
		return (NULL);
	actual_env->next = NULL;
	fresh = actual_env;
	while (env[++i])
	{
		split_them(&fresh, env, i);
		if (!env[i + 1])
			break ;
		if (!(fresh->next = (t_t *)malloc(sizeof(t_t))))
			return (NULL);
		fresh = fresh->next;
	}
	fresh->next = NULL;
	return (actual_env);
}

void		print_msg(t_t *env, int tr)
{
	char	buff[MAX_SIZE];
	char	*ptr;
	char	*tmp;

	ptr = getcwd(buff, MAX_SIZE);
	tmp = NULL;
	if (tr == 0)
		mini_printf("\033[1;31m");
	else
		mini_printf("\033[1;32m");
	if (ptr == NULL)
		tmp = ft_strdup(ft_strrchr(ft_lstsearch(env, "PWD"), '/') + 1);
	else
	{
		if (!ft_strcmp(ptr, "/"))
			tmp = ft_strdup(ptr);
		else
			tmp = ft_strdup(ft_strrchr(ptr, '/') + 1);
	}
	mini_printf("➜  \033[1;36m%s", tmp);
	if (check_file(".git"))
		mini_printf("\033[1;34m git:(\033[1;31mmaster\033[1;34m)");
	mini_printf("\033[0m ");
	ft_strdel(&tmp);
}

void		fun(int segm)
{
	(void)segm;
	mini_printf("\n");
	if (g_check != 1)
		print_msg(g_env, 0);
	g_check = -1;
}

int			main(int ac, char **av, char **env)
{
	char	*input;
	t_t		*t_env;

	t_env = NULL;
	input = NULL;
	(void)ac;
	(void)av;
	t_env = init_env(env);
	signal(SIGINT, fun);
	while (1)
	{
		g_env = t_env;
		g_check = 0;
		if (g_check == 0)
			print_msg(t_env, 1);
		get_next_line(0, &input);
		g_check = 1;
		t_env = exec_cmd(input, t_env);
		ft_strdel(&input);
	}
	free_list(&t_env);
	return (0);
}
