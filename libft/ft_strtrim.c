/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:45:13 by yohan.h           #+#    #+#             */
/*   Updated: 2024/04/15 12:17:19 by yohan.h          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_verif(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	void	loop(char const *s1, char *str, size_t *i, size_t *j)
{
	size_t	k;

	k = 0;
	while (*i <= *j)
	{
		str[k] = s1[*i];
		*i = *i + 1;
		k++;
	}
	str[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 && !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	end--;
	while (s1[start] && ft_verif(s1[start], set) == 1)
		start++;
	while (end > start && ft_verif(s1[end], set) == 1)
		end--;
	str = (char *)malloc(((end + 1) - start) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	loop(s1, str, &start, &end);
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	char const	*s1 = "";
// 	char const	*set = " \n\t";
// 	char		*str;
// 	str = ft_strtrim(s1, set);	
// 	printf("My function : %s\nlen : %ld", str, ft_strlen(str));
// 	free(str);
// 	return (0);
// }