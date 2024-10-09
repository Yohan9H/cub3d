/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yohan.H <yhurtebize58@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:11:25 by Yohan.H           #+#    #+#             */
/*   Updated: 2024/03/20 13:47:49 by Yohan.H          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cpy_b;
	size_t			i;

	cpy_b = (unsigned char *)b;
	i = 0;
	while (i != len)
	{
		cpy_b[i] = (unsigned char )c;
		i++;
	}
	return (b);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int	main()
{
	int	*tab_r = malloc(100 * sizeof(void));
	if (!tab_r)
		return (1);
	int	*tab = malloc(100 * sizeof(void));
	if (!tab)
		return (1);
	int	c = 36;
	size_t	len = 3;

	memset(tab_r, c, len);
	printf("Real function : %s\n", (char *)tab_r);
	free(tab_r);

	ft_memset(tab, c, len);
	printf("My function   : %s\n", (char *)tab);
	free(tab);

	return (0);
}*/
