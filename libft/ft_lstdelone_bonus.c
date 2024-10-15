/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:25:06 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 15:15:41 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_map *lst)
{
	free(lst->line);
	free(lst);
}

// void	del(void * data)
// {
// 	free(data);
// }

// #include <stdio.h>
// int	main()
// {
// 	t_list	*lst_1;

//     lst_1 = (t_list *)malloc(sizeof(t_list));

// 	lst_1->content = ft_strdup("salut");
// 	lst_1->next = NULL;

// 	printf("%s\n", (char *)lst_1->content);
// 	ft_lstdelone(lst_1, &del);
// 	if (lst_1->content)
// 		printf("still here");
// 	free(lst_1);
// 	return (0);
// }