/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:24 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 16:19:57 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_data *data)
{
	t_player *player;

	player = data->game->player;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	player->pos.x = 22;
	player->pos.y = 12;
	raycasting(data, player);
}
