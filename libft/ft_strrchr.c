/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:47:13 by yohan.h           #+#    #+#             */
/*   Updated: 2024/05/20 12:18:02 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cpy_c;
	int		i;

	i = 0;
	cpy_c = (char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == cpy_c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

/*#include <string.h>
#include <stdio.h>
int	main()
{
 	const char	s[] = "tripouille";
 //	char		c = 0;

 	printf("My function   : %s\n", ft_strrchr(s, 0));
 	printf("Reel function : %s\n", strrchr(s, 0));
}*/
