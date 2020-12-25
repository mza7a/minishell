/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmzah <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:10:36 by hmzah             #+#    #+#             */
/*   Updated: 2019/11/15 20:58:07 by hmzah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putstr_cus(char *str, int *i)
{
	ft_putstr(str);
	*i += 1;
}

void			ft_putnbr_cus(int nb, int *i)
{
	ft_putnbr(nb);
	*i += 1;
}

void			ft_puuts(char c, int *i)
{
	ft_putchar(c);
	*i += 1;
}

void			getting(va_list valist, const char *s, int i)
{
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd' && s[i + 1] == 'd')
			{
				printf_space_int(va_arg(valist, int), va_arg(valist, int));
				i += 2;
			}
			else if (s[i] == 'd' && s[i + 1] == 's')
			{
				printf_space_str(va_arg(valist, int), va_arg(valist, char *));
				i += 2;
			}
			else if (s[i] == 'd')
				ft_putnbr_cus(va_arg(valist, int), &i);
			else if (s[i] == 's')
				ft_putstr_cus(va_arg(valist, char *), &i);
		}
		else
			ft_puuts(s[i], &i);
	}
}

void			mini_printf(char const *s, ...)
{
	va_list		valist;
	int			i;

	i = 0;
	va_start(valist, s);
	getting(valist, s, i);
	va_end(valist);
}
