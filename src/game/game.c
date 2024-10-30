/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:42:24 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/30 14:24:29 by yohurteb         ###   ########.fr       */
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
			exit_clean(data, EXIT_FAILURE);
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
	if (dir == EA)
		angle = 90;
	else if (dir == SO)
		angle = 0;
	else if (dir == NO)
		angle = 180;
	else if (dir == WE)
		angle = 270;
	radian = angle * M_PI / 180.0f;
	player->dir.x = cos(radian);
	player->dir.y = sin(radian);
	player->plane.x = FOV * sin(radian);
	player->plane.y = FOV * -cos(radian);
}

void	init_pos(t_player *player)
{
	player->pos.x = player->pos.x + DELTA;
	player->pos.y = player->pos.y + DELTA;
}

void	game(t_data *data)
{
	t_player	*player;

	player = data->game->player;
	init_pos(player);
	init_dir(data->game->dir, player);
	load_textures(data, data->game);
	raycasting(data, player);
}
