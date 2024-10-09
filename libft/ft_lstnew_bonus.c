/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:39:05 by yohurteb          #+#    #+#             */
/*   Updated: 2024/05/23 11:15:31 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

// #include <stdio.h>
// int	main()
// {
// 	char 	content[] = "lorem ipsum dolor sit";
// 	t_list	*lst;

// 	lst = ft_lstnew(content);
// 	printf("Test 1 : %s\n", (char *)lst->content);
// 	free(lst);
// 	return (0);
// }