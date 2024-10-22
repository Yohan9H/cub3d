/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:20:14 by apernot           #+#    #+#             */
/*   Updated: 2024/10/22 18:06:48 by apernot          ###   ########.fr       */
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

int	is_wall(char **map, t_player *player, int keycode)
{
	int pos_map;
	double delta;
	double x;
	double y;

	delta = 0.5;

	if (keycode == LEFT)
	{
		x = player->pos.x - player->plane.x * delta;
		y = player->pos.y - player->plane.y * delta;
	}
	else if (keycode == RIGHT)
	{
		x = player->pos.x + player->plane.x * delta;
		y = player->pos.y + player->plane.y * delta;
	}
	else if (keycode == FRONT)
	{
		x = player->pos.x + player->dir.x * delta;
		y = player->pos.y + player->dir.y * delta;
	}
	else
	{
		x = player->pos.x - player->dir.x * delta;
		y = player->pos.y - player->dir.y * delta;
	}
	pos_map = (int)map[(int)x][(int)y] - '0';
	//printf("%d\n", pos_map);
	if (pos_map > 0)
		return (1);
	return (0);
}

void handle_key_event(t_data *data, int keycode, int is_pressed)
{
	data->key_states[keycode] = is_pressed;
}

int handle_keydown(int keycode, t_data *data)
{
	data->key_states[keycode] = 1;
	return (0);
}

int handle_keyup(int keycode, t_data *data)
{
	data->key_states[keycode] = 0;
	return (0);
}

int	handle_keys(t_data *data)
{
	t_player	*player;
	double 		old_dir_x;
	double 		old_plane_x;

	player = data->game->player;

	if (data->key_states[LEFT] && !is_wall(data->game->map, player, LEFT))
	{
		player->pos.x = player->pos.x - player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->plane.y * MOVE_SPEED;
	}
	if (data->key_states[RIGHT] && !is_wall(data->game->map, player, RIGHT))
	{
		player->pos.x = player->pos.x + player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->plane.y * MOVE_SPEED;
	}
	if (data->key_states[FRONT] && !is_wall(data->game->map, player, FRONT))
	{
		player->pos.x = player->pos.x + player->dir.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->dir.y * MOVE_SPEED;
	}
	if (data->key_states[BACK] && !is_wall(data->game->map, player, BACK))
	{
		player->pos.x = player->pos.x - player->dir.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->dir.y * MOVE_SPEED;
	}

	if (data->key_states[ROT_RIGHT])
	{
		old_dir_x = player->dir.x;
		old_plane_x = player->plane.x;
		player->dir.x = player->dir.x * cos(-ROT_SPEED) - \
			player->dir.y * sin(-ROT_SPEED);
		player->dir.y = old_dir_x * sin(-ROT_SPEED) + \
			player->dir.y * cos(-ROT_SPEED);
		player->plane.x = player->plane.x * cos(-ROT_SPEED) - \
			player->plane.y * sin(-ROT_SPEED);
		player->plane.y = old_plane_x * sin(-ROT_SPEED) + \
			player->plane.y * cos(-ROT_SPEED);
	}
	if (data->key_states[ROT_LEFT])
	{
		old_dir_x = player->dir.x;
		old_plane_x = player->plane.x;
		player->dir.x = player->dir.x * cos(ROT_SPEED) - \
			player->dir.y * sin(ROT_SPEED);
		player->plane.x = player->plane.x * cos(ROT_SPEED) - \
			player->plane.y * sin(ROT_SPEED);
		player->dir.y = old_dir_x * sin(ROT_SPEED) + \
			player->dir.y * cos(ROT_SPEED);
		player->plane.y = old_plane_x * sin(ROT_SPEED) + \
			player->plane.y * cos(ROT_SPEED);
	}
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

int	load_textures(t_data *data, t_game *game)
{
	int i;
	
	i = 0;
	while (i < 3)
	{
		int width;
		int	height;
		game->textures[i]->img = mlx_xpm_file_to_image(data->mlx, data->game->textures[i]->path, &width, &height);
		if (!game->textures[i])
		{
			fprintf(stderr, "Erreur: Impossible de charger la texture %s\n", game->textures[i]->path);
			return (0);
		}
		game->textures[i]->addr = mlx_get_data_addr\
			(data->game->textures[i]->img, &data->game->textures[i]->p_bi, \
				&data->game->textures[i]->l_by, &data->game->textures[i]->endian);
		game->textures[i]->t_w = width;
		game->textures[i]->t_h = height;
		i++;
	}
	return (1);
}

__uint32_t		get_color(t_rvb *rvb)
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
		if (j < data->game->ray->drEd && j > data->game->ray->drSt)
		{
			tex->texY = (int)texPos & (tex->t_h -1);
			texPos += tex->step;
			offset = (tex->texY * tex->l_by + tex->texX * (tex->p_bi / 8));
			color = *(__uint32_t *)(tex->addr + offset);
			if (data->game->ray->side == 1)
				color = (color >> 1) & 0x7F7F7F;
			pixel_offset = (j * data->line_bytes + i * (data->pixel_bits / 8));
			*(__uint32_t *)(data->addr + pixel_offset) = color;
		}
		else if (j < data->game->ray->drSt)
			my_pixel_put(data, i, j, get_color(data->pars->f_rvb));
		else if (j > data->game->ray->drEd)
			my_pixel_put(data, i, j, get_color(data->pars->c_rvb));
		j++;
	}
}

void	make_wall(t_img *tex, t_player *player, t_ray *ray)
{
	ray->l_Hei = (int)(HEIGHT / ray->pWDist);
	ray->drSt = -ray->l_Hei / 2 + HEIGHT / 2;
	if (ray->drSt < 0)
		ray->drSt = 0;
	ray->drEd = ray->l_Hei / 2 + HEIGHT / 2;
	if (ray->drEd >= HEIGHT)
		ray->drEd = HEIGHT - 1;
	if (ray->side == 0) 
		ray->wallX = player->pos.y + ray->pWDist * ray->Dir.y;
	else
		ray->wallX = player->pos.x + ray->pWDist * ray->Dir.x;
	ray->f = (int)ray->wallX;
	ray->fwallX = (double)ray->f;
	ray->wallX -= ray->fwallX;
	tex->texX = (int)(ray->wallX * (double)tex->t_w);
	if ((ray->side == 0 && ray->Dir.y > 0) || \
		(ray->side == 1 && ray->Dir.y < 0))
		tex->texX = tex->t_w - tex->texX - 1;
	tex->step = 1.0 * tex->t_h / ray->l_Hei;
}

void	hit(t_ray *ray, char **map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDist.y += ray->deltaDist.y;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if ((int)map[ray->mapX][ray->mapY] - '0' > 0)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->pWDist = (ray->sideDist.x - ray->deltaDist.x);
	else
		ray->pWDist = (ray->sideDist.y - ray->deltaDist.y);
}

void	side_dist(t_ray *ray, t_player *player)
{
	if (ray->Dir.x < 0)
	{
		ray->stepX = -1;
		ray->sideDist.x = (player->pos.x - ray->mapX) * \
			ray->deltaDist.x;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDist.x = (ray->mapX + 1.0 - player->pos.x) * \
			ray->deltaDist.x;
	}
	if (ray->Dir.y < 0)
	{
		ray->stepY = -1;
		ray->sideDist.y = (player->pos.y - ray->mapY) * \
			ray->deltaDist.y;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDist.y = (ray->mapY + 1.0 - player->pos.y) * ray->deltaDist.y;
	}
}

void	ray_init(int i, t_player *player, t_ray *ray)
{
	double	cameraX;

	cameraX = 2 * i / (double)WIDTH -1;
	ray->Dir.x = player->dir.x + player->plane.x * cameraX;
	ray->Dir.y = player->dir.y + player->plane.y * cameraX;
	ray->mapX = (int)player->pos.x;
	ray->mapY = (int)player->pos.y;
	if (ray->Dir.x == 0)
		ray->deltaDist.x = 1e30;
	else
		ray->deltaDist.x = fabs(1 / ray->Dir.x);
	if (ray->Dir.y == 0)
		ray->deltaDist.y = 1e30;
	else
		ray->deltaDist.y = fabs(1 / ray->Dir.y);
}

void	raycasting(t_data *data, t_player *player)
{
	int		i;
	t_ray	*ray;
	t_img	*tex;
	int		texNum;
	int		texPos;
	
	ray = data->game->ray;
	i = 0;
	load_textures(data, data->game);
	while (i < WIDTH)
	{
		ray_init(i, player, data->game->ray);
		side_dist(ray, player);
		hit(ray, data->game->map);
		texNum = (int)data->game->map[ray->mapX][ray->mapY] - '0' - 1;
		tex = data->game->textures[texNum];
		make_wall(tex, player, ray);
		texPos = (ray->drSt - HEIGHT / 2 + ray->l_Hei / 2) * tex->step;
		fill_wall(data, data->game->textures[texNum], i, texPos);
		i++;
	}
}
