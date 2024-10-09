/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:35:45 by Yohan.H           #+#    #+#             */
/*   Updated: 2024/05/17 16:13:29 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*cpy_dest;
	unsigned char	*cpy_src;
	size_t			i;

	if (!dest && !src && size != 0)
		return (NULL);
	cpy_dest = (unsigned char *)dest;
	cpy_src = (unsigned char *)src;
	i = 0;
	while (i != size)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	return (dest);
}

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int     main()
{
    char        dest[100];
	memset(dest, 'A', 100);
    const char  *src = "coucou";
    size_t      size = 0;

    char        dest_r[100];
	memset(dest_r, 'A', 100);
    const char  *src_r = "coucou";
    size_t      size_r = 0;

    // dest = (char *)malloc(size * sizeof(char));
    ft_memcpy(dest, src, size);
    printf("My function   : %s\n", dest);
    // free(dest);

    // dest_r = (char *)malloc(size_r * sizeof(char));
    memcpy(dest_r, src_r, size_r);
    printf("Reel function : %s\n", dest_r);
    // free(dest_r);

    return (0);
}*/
