/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:02:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/22 14:40:55 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *data)
{
	// int	i = 0;
	// t_map *lst = data->pars->head_map;
	// printf("\n/////////////\n");
	// printf("MAP IN LINKED LIST\n\n");
	// while (lst->line)
	// {
	// 	printf("%s", lst->line);
	// 	lst = lst->next;
	// }
	// printf("\n/////////////\n");
	// printf("MAP IN DATA\n\n");
	// while (data->game->map[i])
	// {
	// 	printf("%s", data->game->map[i]);
	// 	i++;
	// }
	printf("\n/////////////");
	printf("SIZE MAP\n\n");
	printf("y = %d  x = %d", data->pars->size_tab->y, data->pars->size_tab->x);
	printf("\n/////////////");
	printf("TEXTURES\n\n");
	char	*north = data->game->textures[0]->path;
	char	*south = data->game->textures[1]->path; 
	char	*weast = data->game->textures[2]->path; 
	char	*east = data->game->textures[3]->path; 
	printf("N = %s\nS = %s\nW = %s\nE = %s\n", north, south, weast, east);
	printf("\n");
}
