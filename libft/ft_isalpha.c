/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:43:24 by yohan.h           #+#    #+#             */
/*   Updated: 2024/10/21 15:55:35 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

/*#include <ctype.h>
#include <stdio.h>
int	main()
{
	int	c = 'a';

	printf("My function   : %d\n", ft_isalpha(c));
	printf("Reel function : %d\n", isalpha(c));

	return (0);
}*/
