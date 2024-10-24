/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:20:14 by apernot           #+#    #+#             */
/*   Updated: 2024/10/24 10:38:36 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook_put(t_data *data, t_player *player)
{
	if (!data)
		return ;
	raycasting(data, player);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	wall_condition(int keycode, t_player *player, char **map)
{
	t_vector	p;

	if (keycode == LEFT)
	{
		p.x = player->pos.x - player->plane.x * DELTA;
		p.y = player->pos.y - player->plane.y * DELTA;
	}
	else if (keycode == RIGHT)
	{
		p.x = player->pos.x + player->plane.x * DELTA;
		p.y = player->pos.y + player->plane.y * DELTA;
	}
	else if (keycode == FRONT)
	{
		p.x = player->pos.x + player->dir.x * DELTA;
		p.y = player->pos.y + player->dir.y * DELTA;
	}
	else if (keycode == BACK)
	{
		p.x = player->pos.x - player->dir.x * DELTA;
		p.y = player->pos.y - player->dir.y * DELTA;
	}
	return ((int)map[(int)p.x][(int)p.y] - '0');
}

int	is_wall(char **map, t_player *player, int keycode)
{
	int		pos_map;

	pos_map = wall_condition(keycode, player, map);
	if (pos_map > 0)
		return (1);
	return (0);
}

int	handle_keytoogle(int keycode, t_data *data)
{
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

void	handle_move(t_data *data, t_player *player)
{
	if (data->key_states->left && !is_wall(data->game->map, player, LEFT))
	{
		player->pos.x = player->pos.x - player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->plane.y * MOVE_SPEED;
	}
	if (data->key_states->right && !is_wall(data->game->map, player, RIGHT))
	{
		player->pos.x = player->pos.x + player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->plane.y * MOVE_SPEED;
	}
	if (data->key_states->front && !is_wall(data->game->map, player, FRONT))
	{
		player->pos.x = player->pos.x + player->dir.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->dir.y * MOVE_SPEED;
	}
	if (data->key_states->back && !is_wall(data->game->map, player, BACK))
	{
		player->pos.x = player->pos.x - player->dir.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->dir.y * MOVE_SPEED;
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
	if (data->key_states->esc)
		exit_clean(data, EXIT_SUCCESS);
	handle_move(data, player);
	handle_rotation(data, player);
	hook_put(data, player);
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_bytes + x * (data->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_bytes + x * (data->pixel_bits / 8));
	return (*(unsigned int *)dst);
}

__uint32_t	get_color(t_rvb *rvb)
{
	return ((rvb->r << 16) | (rvb->v << 8) | rvb->b);
}

void	fill_wall(t_data *data, t_img *tex, int i, double texPos)
{
	int			j;
	int			pixel_offset;
	int			offset;
	__uint32_t	color;

	j = 0;
	while (j < HEIGHT)
	{	
		if (j <= data->game->ray->dred && j >= data->game->ray->drst)
		{
			tex->texY = (int)texPos & (tex->t_h - 1);
			texPos += tex->step;
			offset = (tex->texY * tex->l_by + tex->texX * (tex->p_bi / 8));
			color = *(__uint32_t *)(tex->addr + offset);
			if (data->game->ray->side == 1)
				color = (color >> 1) & 0x7F7F7F;
			pixel_offset = (j * data->line_bytes + i * (data->pixel_bits / 8));
			*(__uint32_t *)(data->addr + pixel_offset) = color;
		}
		else if (j < data->game->ray->drst)
			my_pixel_put(data, i, j, get_color(data->pars->f_rvb));
		else if (j > data->game->ray->dred)
			my_pixel_put(data, i, j, get_color(data->pars->c_rvb));
		j++;
	}
}

void	make_wall(t_img *tex, t_player *player, t_ray *ray)
{
	ray->l_hei = (int)(HEIGHT / ray->pwdist);
	ray->drst = -ray->l_hei / 2 + HEIGHT / 2;
	if (ray->drst < 0)
		ray->drst = 0;
	ray->dred = ray->l_hei / 2 + HEIGHT / 2;
	if (ray->dred >= HEIGHT)
		ray->dred = HEIGHT - 1;
	if (ray->side == 0)
		ray->wallx = player->pos.y + ray->pwdist * ray->dir.y;
	else
		ray->wallx = player->pos.x + ray->pwdist * ray->dir.x;
	ray->f = (int)ray->wallx;
	ray->fwallx = (double)ray->f;
	ray->wallx -= ray->fwallx;
	tex->texX = (int)(ray->wallx * (double)tex->t_w);
	if ((ray->side == 0 && ray->dir.x > 0) || \
		(ray->side == 1 && ray->dir.y < 0))
		tex->texX = tex->t_w - tex->texX - 1;
	tex->step = 1.0 * tex->t_h / ray->l_hei;
}

void	hit(t_ray *ray, char **map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if ((int)map[ray->mapx][ray->mapy] - '0' > 0)
		{
			ray->hit = 1;
		}
	}
	if (ray->side == 0)
		ray->pwdist = (ray->sidedist.x - ray->deltadist.x);
	else
		ray->pwdist = (ray->sidedist.y - ray->deltadist.y);
}

void	side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->stepx = -1;
		ray->sidedist.x = (player->pos.x - ray->mapx) * ray->deltadist.x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedist.x = (ray->mapx + 1.0 - player->pos.x) * ray->deltadist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->stepy = -1;
		ray->sidedist.y = (player->pos.y - ray->mapy) * ray->deltadist.y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedist.y = (ray->mapy + 1.0 - player->pos.y) * ray->deltadist.y;
	}
}

void	ray_init(int i, t_player *player, t_ray *ray)
{
	double	camerax;

	camerax = 2 * i / (double)WIDTH -1;
	ray->dir.x = player->dir.x + player->plane.x * camerax;
	ray->dir.y = player->dir.y + player->plane.y * camerax;
	ray->mapx = (int)player->pos.x;
	ray->mapy = (int)player->pos.y;
	if (ray->dir.x == 0)
		ray->deltadist.x = 1e30;
	else
		ray->deltadist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->deltadist.y = 1e30;
	else
		ray->deltadist.y = fabs(1 / ray->dir.y);
}

int	which_texture(t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->dir.y > 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (ray->dir.x > 0)
			return (3);
		else
			return (2);
	}
}

void	raycasting(t_data *data, t_player *player)
{
	int		i;
	t_ray	*ray;
	t_img	*tex;
	int		texnum;
	int		texpos;

	ray = data->game->ray;
	i = 0;
	while (i < WIDTH)
	{
		ray_init(i, player, data->game->ray);
		side_dist(ray, player);
		hit(ray, data->game->map);
		texnum = which_texture(ray);
		tex = data->game->textures[texnum];
		make_wall(tex, player, ray);
		texpos = (ray->drst - HEIGHT / 2 + ray->l_hei / 2) * tex->step;
		fill_wall(data, data->game->textures[texnum], i, texpos);
		i++;
	}
}
