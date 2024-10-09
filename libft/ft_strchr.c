/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:22:23 by yohan.h           #+#    #+#             */
/*   Updated: 2024/05/24 13:58:24 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cpy_c;
	int		i;

	i = 0;
	cpy_c = (char)c;
	while (s[i])
	{
		if (s[i] == cpy_c)
			return ((char *)&s[i]);
		i++;
	}
	if (cpy_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
int	main()
{
 	const char	s[] = "salut";
 	char		c = '\0';

 	printf("My function   : %s\n", ft_strchr(s, (int)c));
 	printf("Reel function : %s\n", strchr(s, (int)c));
}*/
