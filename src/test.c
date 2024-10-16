/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:02:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/16 18:39:30 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *data)
{
	int	i = 0;
	t_map *lst = data->pars->head_map;
	// char **cpy = ft_strdup_double_array(data, data->game->map);
	printf("\n/////////////\n");
	printf("MAP IN LINKED LIST\n\n");
	while (lst->line)
	{
		printf("%s", lst->line);
		lst = lst->next;
	}
	printf("\n/////////////\n");
	printf("MAP IN DATA\n\n");
	while (data->game->map[i])
	{
		printf("%s", data->game->map[i]);
		i++;
	}
	// printf("\n/////////////\n");
	// printf("MAP CPY WITH STRDUP_DBL_ARRAY\n\n");
	// i = 0;
	// while (cpy[i])
	// {
	// 	printf("%s", cpy[i]);
	// 	i++;
	// }
	printf("\n");
}
