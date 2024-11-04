/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:20:14 by apernot           #+#    #+#             */
/*   Updated: 2024/11/04 10:37:04 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "cub3d.h"

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
	tex->texx = (int)(ray->wallx * (double)tex->t_w);
	if ((ray->side == 0 && ray->dir.x > 0) || \
		(ray->side == 1 && ray->dir.y < 0))
		tex->texx = tex->t_w - tex->texx - 1;
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
