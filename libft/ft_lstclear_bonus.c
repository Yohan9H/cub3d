/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:32:43 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 11:48:03 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_map **lst)
{
	t_map	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->line);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void	del(void * data)
// {
// 	free(data);
// }
//
// #include <stdio.h>
// int	main()
// {
// 	t_list	*lst_1;
//
//     lst_1 = (t_list *)malloc(sizeof(t_list));
//
// 	lst_1->content = ft_strdup("salut");
// 	lst_1->next = NULL;

// 	ft_lstclear(&lst_1, &del);
// 	if (lst_1 == NULL)
// 		printf("GOOD !\n");
// 	free(lst_1);
// 	return (0);
// }