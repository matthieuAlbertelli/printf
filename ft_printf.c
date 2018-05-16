/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:16:33 by malberte          #+#    #+#             */
/*   Updated: 2018/05/16 23:46:23 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "flags.h"

static char	*putstrc(ssize_t *written_char, const char *s, char c)
{
	ssize_t	len;
	ssize_t count;

	if (s == NULL)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != c)
		++len;
	count = write (1, s, len);
	if (count < 0 || count != len)
		return (NULL);
	*written_char += count;
	return (((char *)&(s[len])));
}

int			ft_printf(const char *format, ...)
{
	va_list	lst;
	char	*s;
	ssize_t	written_char;

	written_char = 0;
	va_start(lst, format);
	s = (char *)format;
	while (*s)
	{
		s = putstrc(&written_char, s, ARG_TAG);
		if (*s == ARG_TAG)
		{
			
		}

	}
	va_end(lst);
	return (1);
}