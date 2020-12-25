/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:42:27 by hmzah             #+#    #+#             */
/*   Updated: 2019/04/14 22:51:03 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*fresh;

	if ((fresh = (t_list *)malloc(sizeof(t_list))))
	{
		if (content == NULL)
		{
			fresh->content = NULL;
			fresh->content_size = 0;
		}
		else
		{
			fresh->content = malloc(content_size);
			ft_memcpy(fresh->content, content, content_size);
			fresh->content_size = content_size;
		}
		fresh->next = NULL;
		return (fresh);
	}
	else
		return (NULL);
}
