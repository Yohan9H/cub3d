/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan.h <yohan.h@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:39:41 by Yohan.H           #+#    #+#             */
/*   Updated: 2024/05/24 12:36:08 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif_mem(unsigned char *dest, const unsigned char *src)
{
	if (src < dest)
		return (1);
	else
		return (0);
}

static void	ft_mem_true(unsigned char *dst, const unsigned char *src, size_t l)
{
	while (l > 0)
	{
		dst[l - 1] = src[l - 1];
		l--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*cpy_dest;
	const unsigned char	*cpy_src;
	unsigned int		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	cpy_dest = (unsigned char *)dest;
	cpy_src = (const unsigned char *)src;
	i = 0;
	if (ft_verif_mem(cpy_dest, cpy_src) == 1)
	{
		ft_mem_true(cpy_dest, cpy_src, len);
	}
	else
	{
		while (i < len)
		{
			cpy_dest[i] = cpy_src[i];
			i++;
		}
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>
int		main()
{
	char	src[] = {65, 66, 67, 68, 69, 0, 45};
	//char	dest[] = "Yo mon gars";
	size_t	len = 2;

	char	src_r[] = {65, 66, 67, 68, 69, 0, 45};
	//char	dest_r[] = "Yo gars";
	size_t	len_r = 2;

	ft_memmove(src + 1, src, len);
	printf("My function	  : %s\n", src);

	memmove(src_r + 1, src_r, len_r);
	printf("Reel function : %s\n", src);
}*/
