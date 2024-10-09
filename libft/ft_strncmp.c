/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:17:16 by yohan.h           #+#    #+#             */
/*   Updated: 2024/05/20 12:29:06 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
		n--;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int	main()
// {
// 	const char	s1[] = "test\200";
// 	const char	s2[] = "test\0";
// 	size_t		n = 6;

// 	printf("My function   : %d\n", ft_strncmp(s1, s2, n));
// 	printf("Reel function : %d\n", strncmp(s1, s2, n));
// }
