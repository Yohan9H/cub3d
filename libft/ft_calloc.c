/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:08:18 by yohan.h           #+#    #+#             */
/*   Updated: 2024/05/16 10:47:05 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb * size < size && nmemb * size != 0)
		return (NULL);
	s = (void *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str;
// 	size_t	count = -5;
// 	size_t	size = -5;

// 	printf("My function   : ");
// 	str = (char *)ft_calloc(count, size);
//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", str[i]);
// 	}
// 	printf("\n");
// 	free(str);

// 	printf("Reel function : ");
// 	str = (char *)calloc(count, size);
//     for (size_t i = 0; i < count; i++) {
//         printf("%d ", str[i]);
// 	}
// 	printf("\n");
// 	free(str);
// 	return (0);
// }