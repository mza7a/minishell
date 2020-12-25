/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 03:53:30 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/18 00:09:39 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <string.h>
# include <dirent.h>
# define MAX_SIZE 1024

typedef	struct		s_tree
{
	char			*key;
	char			*value;
	struct s_tree	*next;
}					t_t;

/*
**	builtins/
*/

void				ft_cd(char **tab, t_t ***env);
void				ft_echo(char **str);
void				ft_env(t_t *env);
void				ft_exit(char ***final, t_t **env, char **input);
void				ft_setenv(t_t ***env, char **final);
void				ft_unsetenv(t_t ***env, char **final);

/*
**	tools.c
*/

void				check_file_perm(char *path);
int					check_file(char *path);
void				split_them(t_t **fresh, char **env, int index);

/*
**	exec_cmd.c
*/

t_t					*exec_cmd(char *input, t_t *env);

/*
**	builtins.c
*/

int					check_builtins(char *cmd);
void				do_builtins(char ***final, t_t **env, char **input);

/*
**	list_tools.c
*/

void				free_list(t_t **env);
char				*ft_lstsearch(t_t *env, char *to_search);
int					lst_size(t_t *env);
void				print_lst(t_t *env);
char				**lst_array(t_t *env);

/*
**	expansions.c
*/

void				expansions(char ***tab, t_t *env);

/*
**	minishell.c
*/

void				free_list(t_t **env);

#endif
