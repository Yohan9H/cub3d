/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:37:16 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/22 19:46:09 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen)
{
	size_t	i;

	i = 0;
	if (dstlen == 0)
		return (ft_strlen(src));
	while (src[i] && dstlen - 1 > 0)
	{
		dst[i] = src[i];
		dstlen--;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>
// #define nb 6
// int	main()
// {
// 	char		dst[10];
// 	memset(dst, 'A', 10);
// 	const char	src[] = "coucou";
// 	size_t		dstlen = nb;

// 	char		dst_r[10];
// 	memset(dst_r, 'A', 10);
// 	const char	src_r[] = "coucou";
// 	size_t		dstlen_r = nb;

// 	printf("My function   : %lu\n", ft_strlcpy(dst, src, dstlen));
// 	printf("dst   : %s\n", dst);
// 	printf("src   : %s\n----------\n", src);
// 	printf("Reel function : %lu\n", strlcpy(dst_r, src_r, dstlen_r));
// 	printf("dst_r : %s\n", dst_r);
// 	printf("src_r : %s\n", src_r);
// 	return (0);
// }