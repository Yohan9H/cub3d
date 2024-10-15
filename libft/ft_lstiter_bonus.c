/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:46:33 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 15:16:07 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_map *lst)
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		free(lst->line);
		lst = lst->next;
	}
}
