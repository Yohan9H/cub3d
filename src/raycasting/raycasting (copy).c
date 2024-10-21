/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:20:14 by apernot           #+#    #+#             */
/*   Updated: 2024/10/21 14:50:53 by apernot          ###   ########.fr       */
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

int	handle_keys(int keycode, t_data *data)
{
	t_player	*player;

	player = data->game->player;
	if (keycode == LEFT)
	{
		player->pos.x = player->pos.x - player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->plane.y * MOVE_SPEED;
	}
	else if (keycode == RIGHT)
	{
		player->pos.x = player->pos.x + player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->plane.y * MOVE_SPEED;
	}
	else if (keycode == FRONT)
	{
		player->pos.x = player->pos.x + player->dir.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->dir.y * MOVE_SPEED;
	}
	else if (keycode == BACK)
	{
		player->pos.x = player->pos.x - player->dir.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->dir.y * MOVE_SPEED;
	}
	else if (keycode == ROT_RIGHT)
	{
		player->dir.x = player->dir.x * cos(-ROT_SPEED) - \
			player->dir.y * sin(-ROT_SPEED);
		player->plane.x = player->plane.x * cos(-ROT_SPEED) - \
			player->plane.y * sin(-ROT_SPEED);
		player->dir.y = player->dir.x * sin(-ROT_SPEED) + \
			player->dir.y * cos(-ROT_SPEED);
		player->plane.y = player->plane.x * sin(-ROT_SPEED) + \
			player->plane.y * cos(-ROT_SPEED);
	}
	else if (keycode == ROT_LEFT)
	{
		player->dir.x = player->dir.x * cos(ROT_SPEED) - \
			player->dir.y * sin(ROT_SPEED);
		player->plane.x = player->plane.x * cos(ROT_SPEED) - \
			player->plane.y * sin(ROT_SPEED);
		player->dir.y = player->dir.x * sin(ROT_SPEED) + \
			player->dir.y * cos(ROT_SPEED);
		player->plane.y = player->plane.x * sin(ROT_SPEED) + \
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
	// Liste des chemins vers les fichiers XPM
	const char	*texture_files[8] = {
		"textures/eagle.xpm",
		"textures/redbrick.xpm",
		"textures/purplestone.xpm",
		"textures/greystone.xpm",
		"textures/bluestone.xpm",
		"textures/mossy.xpm",
		"textures/wood.xpm",
		"textures/colorstone.xpm"
	};

	for (int i = 0; i < 7; i++)
	{
		int width;
		int	height;
		game->textures[i]->img = mlx_xpm_file_to_image(data->mlx, (char *)texture_files[i], &width, &height);
		if (!game->textures[i])
		{
			fprintf(stderr, "Erreur : Impossible de charger la texture %s\n", texture_files[i]);
			return (0);
		}
		game->textures[i]->addr = mlx_get_data_addr\
			(data->game->textures[i]->img, &data->game->textures[i]->p_bi, \
				&data->game->textures[i]->l_by, &data->game->textures[i]->endian);
		game->textures[i]->t_w = width;
		game->textures[i]->t_h = height;
	}
	return (1);
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
			my_pixel_put(data, i, j, 0x3F3F3F);
		else if (j > data->game->ray->drEd)
			my_pixel_put(data, i, j, 0x7D7D7D);
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

void	hit(t_ray *ray, int map[24][24])
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
		if (map[ray->mapX][ray->mapY] > 0)
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
	int	cameraX;

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
	int map[24][24] = 
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
	ray = data->game->ray;
	i = 0;
	load_textures(data, data->game);
	while (i < WIDTH)
	{
		ray_init(i, player, data->game->ray);
		side_dist(ray, player);
		hit(ray, map);
		texNum = map[ray->mapX][ray->mapY] - 1;
		tex = data->game->textures[texNum];
		make_wall(tex, player, ray);
		texPos = (ray->drSt - HEIGHT / 2 + ray->l_Hei / 2) * tex->step;
		fill_wall(data, data->game->textures[texNum], i, texPos);
		i++;
	}
}
