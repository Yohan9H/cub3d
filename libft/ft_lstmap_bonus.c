/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:47:53 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 15:18:04 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_map	*ft_lstmap(t_map *lst)
{
	t_map	*new_lst;
	t_map	*new_node;
	void	*temp_content;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		temp_content = lst->line;
		new_node = ft_lstnew(temp_content);
		if (!new_node)
		{
			free(temp_content);
			ft_lstclear(&new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
