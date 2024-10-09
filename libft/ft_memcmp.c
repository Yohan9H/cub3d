/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yohan.H <yhurtebize58@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:17:02 by Yohan.H           #+#    #+#             */
/*   Updated: 2024/05/20 11:02:02 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;
	unsigned int	i;

	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cpy_s1[i] != cpy_s2[i])
		{
			return (cpy_s1[i] - cpy_s2[i]);
		}
		i++;
	}
	return (0);
}

/*#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int	main()
{
	const char	s1[] = {-128, 0, 127, 0};
	const char	s2[] = {-128, 0, 127, 0};
	size_t 		n = 4;
	int			res = ft_memcmp(s1, s2, n);
	int			res_r = memcmp(s1, s2, n);

	printf("My function   : %d\n", res);
	printf("Reel function : %d\n", res_r);

	return (0);
}*/
