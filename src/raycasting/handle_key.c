/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:41:08 by apernot           #+#    #+#             */
/*   Updated: 2024/10/28 12:05:02 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keytoogle(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		exit_clean(data, EXIT_SUCCESS);
	if (keycode == XK_w || keycode == XK_W)
		data->key_states->front ^= 1;
	if (keycode == XK_s || keycode == XK_S)
		data->key_states->back ^= 1;
	if (keycode == XK_a || keycode == XK_A)
		data->key_states->left ^= 1;
	if (keycode == XK_d || keycode == XK_D)
		data->key_states->right ^= 1;
	if (keycode == XK_Left)
		data->key_states->rot_l ^= 1;
	if (keycode == XK_Right)
		data->key_states->rot_r ^= 1;
	return (0);
}

double	calc_move_speed(t_state *ks)
{
	double	move_speed;

	move_speed = MOVE_SPEED;
	if ((ks->front && (ks->left || ks->right)) || \
		(ks->back && (ks->left || ks->right)))
	{
		move_speed = MOVE_SPEED / sqrt(2);
	}
	return (move_speed);
}

void	handle_move(t_state *ks, char **map, t_player *player)
{
	double	move_speed;

	move_speed = calc_move_speed(ks);
	if (ks->left && !is_wall(map, player, LEFT))
	{
		player->pos.x = player->pos.x - player->plane.x * move_speed;
		player->pos.y = player->pos.y - player->plane.y * move_speed;
	}
	if (ks->right && !is_wall(map, player, RIGHT))
	{
		player->pos.x = player->pos.x + player->plane.x * move_speed;
		player->pos.y = player->pos.y + player->plane.y * move_speed;
	}
	if (ks->front && !is_wall(map, player, FRONT))
	{
		player->pos.x = player->pos.x + player->dir.x * move_speed;
		player->pos.y = player->pos.y + player->dir.y * move_speed;
	}
	if (ks->back && !is_wall(map, player, BACK))
	{
		player->pos.x = player->pos.x - player->dir.x * move_speed;
		player->pos.y = player->pos.y - player->dir.y * move_speed;
	}
}

void	handle_rotation(t_data *data, t_player *player)
{
	double		old_dir_x;
	double		old_plane_x;
	double		rot_speed;

	if (data->key_states->rot_r)
		rot_speed = -ROT_SPEED;
	else if (data->key_states->rot_l)
		rot_speed = ROT_SPEED;
	else
		return ;
	if (data->key_states->rot_r || data->key_states->rot_l)
	{
		old_dir_x = player->dir.x;
		player->dir.x = old_dir_x * cos(rot_speed) - \
			player->dir.y * sin(rot_speed);
		player->dir.y = old_dir_x * sin(rot_speed) + \
			player->dir.y * cos(rot_speed);
		old_plane_x = player->plane.x;
		player->plane.x = old_plane_x * cos(rot_speed) - \
			player->plane.y * sin(rot_speed);
		player->plane.y = old_plane_x * sin(rot_speed) + \
			player->plane.y * cos(rot_speed);
	}
}

int	handle_keys(t_data *data)
{
	t_player	*player;

	player = data->game->player;
	handle_move(data->key_states, data->game->map, player);
	handle_rotation(data, player);
	hook_put(data, player);
	return (0);
}
