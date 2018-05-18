/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 22:16:33 by malberte          #+#    #+#             */
/*   Updated: 2018/05/18 04:16:07 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "flags.h"
#include "ft_printf.h"

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

static int	get_flag_conv(t_specs *format, const char *str)
{
	static const t_flags conv[] = {	CONV_INT, CONV_INT_BIS, CONV_OCTAL,
	CONV_UNSIGNED, CONV_HEXA_LOW, CONV_HEXA_UP, CONV_CHAR, CONV_STR,
	CONV_C_UNICODE, CONV_STR_UNICODE, CONV_VOID_HEXA, 0 };
	int i;
	
	if (*str == '\0')
		return (ERROR);
	++format->specs_len;
	i = 0;
	while(conv[i] && conv[i] != *str)
		++i;
	if(conv[i] == 0)
		return (ERROR);
	format->flag[conv[i]] = TRUE;
	return (conv[i]);
}

static int init_specs(t_specs *specs, const char *str)
{
	specs->specs_len = 0;
	ft_bzero((void *)specs->flag, 128 * sizeof(char));
	specs->len_modifier = 0;
	specs->min_field_width = 0;
	specs->precision = 0;
	if (get_flag_conv(specs, str) == ERROR)
		return (ERROR);
	return(1);
}

int			ft_printf(const char *format, ...)
{
	va_list		lst;
	char 		*s;
	ssize_t		written_char;
	t_specs		specs;

	written_char = 0;
	va_start(lst, format);
	s = (char *)format;
	while (*s)
	{
		s = putstrc(&written_char, s, ARG_TAG);
		if (s == NULL)
			return (ERROR);
		if (*s == ARG_TAG)
		{
			// ++s;
			if (*(s + 1) == ARG_TAG)
			{
				written_char += write(1, s, 1);
				if (written_char != 1)
					return (ERROR);
				s += 2;
			}
			else if (*s == '\0')
				return (ERROR);
			else
			{
				if (init_specs(&specs, s + 1) == ERROR)
				{
					write(1, s, specs.specs_len + 1);
					s += specs.specs_len + 1;
				}
				else
				{
					
				}
			}
		}

	}
	va_end(lst);
	return (written_char);
}