/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malberte <malberte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 21:09:09 by malberte          #+#    #+#             */
/*   Updated: 2018/05/18 02:35:25 by malberte         ###   ########.fr       */
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
	ret = ft_printf("%o", width);
	return (0);
}
