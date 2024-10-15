/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:20:40 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 15:13:24 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_map **lst, t_map *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main()
// {
// 	t_list	*lst;
// 	t_list	new;

// 	ft_lstadd_front(&lst, &new);
// 	return (0);
// }