/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:12:28 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/25 17:54:13 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	res;

	i = 0;
	len_dst = ft_strlen(dst);
	res = len_dst + ft_strlen(src);
	if (len_dst >= size || size == 0)
		return (size + ft_strlen(src));
	while (len_dst + i < size - 1 && src[i])
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (res);
}

// #include <bsd/string.h>
// #include <stdio.h>
// #define NB 2
// #define LEN 18
// int	main()
// {
// 	char		dst[NB] = "";
// 	const char	*src = "salut";
// 	size_t		dstlen = LEN;

// 	char		dst_r[NB] = "";
// 	const char	*src_r = "salut";
// 	size_t		dstlen_r = LEN;

// 	printf("My function   : %zu\n", ft_strlcat(dst, src, dstlen));
// 	printf("dst   : %s\n", dst);
// 	printf("src   : %s\n----------\n", src);
// 	printf("Reel function : %zu\n", strlcat(dst_r, src_r, dstlen_r));
// 	printf("dst_r : %s\n", dst_r);
// 	printf("src_r : %s\n", src_r);
// 	return (0);
// }