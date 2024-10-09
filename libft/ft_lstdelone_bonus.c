/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:25:06 by yohurteb          #+#    #+#             */
/*   Updated: 2024/05/23 15:21:28 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
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