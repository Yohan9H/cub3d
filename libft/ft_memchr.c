/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:25:50 by Yohan.H           #+#    #+#             */
/*   Updated: 2024/03/25 18:45:07 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*src;
	unsigned int	i;

	src = (char *)s;
	i = 0;
	while (i < (unsigned int)n)
	{
		if (src[i] == (char)c)
			return (&src[i]);
		i++;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int	main()
{
	const char	s[] = "salut mon Upote";
	int			c = 85; // U
	size_t		n = strlen(s);
	void	*res;
	void	*res_r;

	res = ft_memchr(s, c, n);
	if (res == NULL)
		printf("My function   : Not found\n");
	else
		printf("My function   : Found --> %s\n", (char *)res);
	res_r = memchr(s, c, n);
	if (res_r == NULL)
		printf("Reel function : Not found\n");
	else
		printf("Reel function : Found --> %s\n", (char *)res_r);
}*/