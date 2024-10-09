/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:43:53 by yohan.h           #+#    #+#             */
/*   Updated: 2024/05/24 14:17:26 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	verify_needle(const char *str, const char *nd, size_t *i)
{
	size_t	k;
	size_t	tmp;

	k = 0;
	tmp = *i;
	while (str[*i] == nd[k] && str[*i])
	{
		*i = *i + 1;
		k++;
	}
	*i = tmp;
	return (k);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	save_len;

	i = 0;
	k = 0;
	save_len = len;
	if (!needle[i])
		return ((char *)&haystack[i]);
	while (len > 0 && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			k = verify_needle(haystack, needle, &i);
			if (i + k > save_len)
				return (NULL);
			if (!needle[k])
				return ((char *)&haystack[i]);
		}
		len--;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int	main()
// {
// 	const char	haystack[] = "aaabcabcd";
// 	const char	needle[] = "abcd";
// 	size_t		len = 9;
//
// 	printf("My function   : %s\n", ft_strnstr(haystack, needle, len));
// 	printf("Reel function : %s\n", strnstr(haystack, needle, len));
// 	return (0);
// }