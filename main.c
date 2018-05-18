/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:09:09 by malberte          #+#    #+#             */
/*   Updated: 2018/05/18 03:17:56 by malberte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int width, num;
	int ret;
	
	width = 10;
	num = 8;
	// printf("%*d", width, num);
	ret = ft_printf("%w", width);
	return (0);
}
