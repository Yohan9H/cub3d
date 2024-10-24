/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:24 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/24 11:45:53 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_textures(t_data *data, t_game *game)
{
	int		i;
	int		width;
	int		height;
	t_img	*tex;

	i = 0;
	while (i < 4)
	{
		tex = game->textures[i];
		tex->img = mlx_xpm_file_to_image(data->mlx, tex->path, &width, &height);
		if (!tex->img)
		{
			fprintf(stderr, "Erreur texture %s\n", game->textures[i]->path);
			return (0);
		}
		tex->addr = mlx_get_data_addr(tex->img, \
			&tex->p_bi, &tex->l_by, &tex->endian);
		tex->t_w = width;
		tex->t_h = height;
		i++;
	}
	return (1);
}

void	init_dir(int dir, t_player *player)
{
	int		angle;
	float	radian;

	angle = 0;
	if (dir == WE)
		angle = 0;
	else if (dir == SO)
		angle = 90;
	else if (dir == EA)
		angle = 180;
	else if (dir == NO)
		angle = 270;
	radian = angle * M_PI / 180.0f;
	player->dir.x = cos(radian);
	player->dir.y = sin(radian);
	player->plane.x = -FOV * sin(radian);
	player->plane.y = FOV * cos(radian);
}


void	game(t_data *data)
{
	t_player	*player;

	player = data->game->player;
	player->dir.x = -1;
	player->dir.y = 0;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = FOV;
	init_dir(data->game->dir, player);
	load_textures(data, data->game);
	raycasting(data, player);
}
