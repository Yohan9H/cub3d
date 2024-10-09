/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:38:29 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/22 18:17:55 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int	main()
{
	int	c = 122;

	printf("My function   : %d\n", ft_isprint(c));
	printf("Reel function : %d\n", isprint(c));
	return (0);
}*/