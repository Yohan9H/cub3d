/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:20:07 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/22 18:33:51 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*#include <string.h>
#include <stdio.h>
int	main()
{
	const char	s[] = " ";

	printf("My function   : %lu\n", ft_strlen(s));
	printf("Reel function : %zu\n", strlen(s));
	return (0);
}*/