/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:02:34 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/24 13:53:07 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *data)
{
	char	*north = data->game->textures[0]->path;
	char	*south = data->game->textures[1]->path; 
	char	*weast = data->game->textures[2]->path; 
	char	*east = data->game->textures[3]->path;
	int	i = 0;

	printf("---> TEXTURES\n");
	printf("N = %s\nS = %s\nW = %s\nE = %s\n", north, south, weast, east);
	printf("\nF = %d,%d,%d\n", data->pars->f_rvb->r, data->pars->f_rvb->v, data->pars->f_rvb->b);
	printf("C = %d,%d,%d\n", data->pars->c_rvb->r, data->pars->c_rvb->v, data->pars->c_rvb->b);
	printf("\n---> MAP\n");
	printf("pos player : [%f] [%f]\n", data->game->player->pos.y, data->game->player->pos.x);
	printf("dir player : %d\n", data->game->dir);
	printf("\nsize map : y = %d  x = %d\n\n", data->pars->size_tab->y, data->pars->size_tab->x);
	while (data->game->map[i])
		printf("%s", data->game->map[i++]);
	printf("\n");
}
