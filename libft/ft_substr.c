/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:25:34 by yohan.h           #+#    #+#             */
/*   Updated: 2024/03/26 17:10:36 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			len_s;
	size_t			len_d;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s - start > len)
		len_d = len;
	else
		len_d = len_s - start;
	str = (char *)malloc(len_d + 1 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len_d + 1);
	return (str);
}

// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char			*s = "0123456789";
// 	//char			*str = strdup("1");
// 	unsigned int	start = 9;
// 	size_t			len = 10;
// 	char			*res;

// 	printf("My function : %s\n", res = ft_substr(s, start, len));
// 	free(res);
// 	return (0);
// }