/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:52:51 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/22 17:02:42 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int	main()
{
	int	c = 57;

	printf("My function   : %d\n", ft_isdigit(c));
	printf("Reel function : %d\n", isdigit(c));
}*/