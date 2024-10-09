/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:58:49 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/25 18:11:19 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>
int	main()
{
	int	c = 24;

	printf("Before c = \'%c\'\n", (char)c);
	printf("My function   : %c\n", (char)ft_toupper(c));
	printf("Reel function : %c\n", (char)toupper(c));
	return (0);
}*/