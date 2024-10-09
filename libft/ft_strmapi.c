/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:35:13 by yohan.h           #+#    #+#             */
/*   Updated: 2024/04/05 22:21:47 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s)) + sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	f(unsigned int i, char c)
// {
// 	(void)i;
// 	c -= 32;
// 	return (c);
// }

// #include <stdio.h>
// int	main()
// {
// 	char const	*s = "salut";
// 	char		*str;

// 	printf("Before : %s\n", s);
// 	printf("After  : %s\n", str = ft_strmapi(s, f));
// 	free(str);
// 	return (0);
// }