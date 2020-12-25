/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <hmzah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 02:05:43 by hmzah             #+#    #+#             */
/*   Updated: 2020/11/13 00:03:53 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_chars(char *str, char *tok)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (tok[j])
		{
			if (str[i] == tok[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int			check_an(char c, char *tok)
{
	int	i;

	i = 0;
	while (tok[i])
	{
		if (tok[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int			count_words(char *str, char *tok)
{
	int		i;
	int		res;
	int		flag;

	i = 0;
	res = 0;
	flag = 0;
	while (str[i])
	{
		if (check_an(str[i], tok))
		{
			res++;
			while (str[i] && check_an(str[i], tok))
				i++;
		}
		while (str[i] && !check_an(str[i], tok))
			i++;
	}
	return (res);
}

char		**do_stuff(int *wcount, char *input, char *token)
{
	char	**tab;

	tab = NULL;
	*wcount = count_words(input, token);
	if (*wcount == 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (*wcount) + 1)))
		return (NULL);
	tab[*wcount] = NULL;
	return (tab);
}

char		**ft_strsplitstr(char *input, char *token)
{
	char	**res;
	int		i;
	int		j;
	int		wcount;
	int		lcount;

	if (!(res = do_stuff(&wcount, input, token)))
		return (NULL);
	i = 0;
	while (i < wcount)
	{
		j = -1;
		res[i] = NULL;
		if (input && !(lcount = count_chars(input, token)))
			input++;
		if (input && lcount)
			res[i] = ft_strnew(lcount);
		while (*input && ++j < lcount && lcount > 0)
			res[i][j] = *(input++);
		if (res[i] || lcount)
			i++;
		if (!*input)
			break ;
	}
	return (res);
}
