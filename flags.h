/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:54:36 by malberte          #+#    #+#             */
/*   Updated: 2018/05/18 02:46:58 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <stdlib.h>
# include "bool.h"
# define ARG_TAG '%'
# define FLAG_CONVERT 0x00

typedef enum    	e_flags
{
    ATT_CONVERT			= '#',
    ATT_ZERO_FILL		= '0',
    ATT_JUSTIFY_LEFT	= '-',
    ATT_BLANK			= ' ',
    ATT_FORCE_SIGNED	= '+',
    PRECISION			= '.',
    LEN_MOD_SHORT		= 'h',
    LEN_MOD_LONG		= 'l',
    LEN_MOD_INT_MAX		= 'j',
    LEN_MOD_SIZE_T		= 'z',
    CONV_INT			= 'd',
    CONV_INT_BIS		= 'i',
    CONV_OCTAL			= 'o',
    CONV_UNSIGNED		= 'u',
    CONV_HEXA_LOW		= 'x',
    CONV_HEXA_UP		= 'X',
    CONV_CHAR			= 'c',
    CONV_STR			= 's',
    CONV_C_UNICODE		= 'C',
    CONV_STR_UNICODE	= 'S',
	CONV_VOID_HEXA		= 'p'
}               	t_flags;

typedef struct		s_specs
{
	char			flag[128];
	unsigned int	precision;
	unsigned int 	min_field_width;
	unsigned int	len_modifier;
	size_t			specs_len;
}					t_specs;

int					ft_getflags(t_specs *specs, const char *str_format);

#endif
