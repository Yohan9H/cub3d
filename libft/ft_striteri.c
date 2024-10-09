/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:24:47 by yohan.h           #+#    #+#             */
/*   Updated: 2024/04/05 22:51:43 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
	return ;
}

/*void	f(unsigned int i, char *s)
{
	(void)i;
	s[0] += 32;
}

#include <stdio.h>
int	main()
{
	char s[] = "SALUT";

	printf("Before : %s\n", s);
	ft_striteri(s, f);
	printf("After  : %s\n", s);
	return (0);
}*/