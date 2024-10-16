/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:20:14 by apernot           #+#    #+#             */
/*   Updated: 2024/10/15 16:38:23 by apernot          ###   ########.fr       */
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
		player->dir.x = player->dir.x * cos(-ROT_SPEED) - player->dir.y * sin(-ROT_SPEED);
		player->plane.x = player->plane.x * cos(-ROT_SPEED) - player->plane.y * sin(-ROT_SPEED);
		player->dir.y = player->dir.x * sin(-ROT_SPEED) + player->dir.y * cos(-ROT_SPEED);
		player->plane.y = player->plane.x * sin(-ROT_SPEED) + player->plane.y * cos(-ROT_SPEED);
	}
	else if (keycode == ROT_LEFT)
	{
		player->dir.x = player->dir.x * cos(ROT_SPEED) - player->dir.y * sin(ROT_SPEED);
		player->plane.x = player->plane.x * cos(ROT_SPEED) - player->plane.y * sin(ROT_SPEED);
		player->dir.y = player->dir.x * sin(ROT_SPEED) + player->dir.y * cos(ROT_SPEED);
		player->plane.y = player->plane.x * sin(ROT_SPEED) + player->plane.y * cos(ROT_SPEED);
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

void	verLine(t_data *data, double x, int drawStart, int drawEnd, int color)
{
	int	i;

	i = 0;
	while (i <= HEIGHT)
	{
		if (i < drawStart)
			my_pixel_put(data, x, i, 0x3F3F3F);
		else if (i > drawEnd)
			my_pixel_put(data, x, i, 0x7D7D7D);
		else
			my_pixel_put(data, x, i, color);
		i++;
	}
}

void	raycasting(t_data *data, t_player *player)
{
	int	i;
	double cameraX;
	int	color;
	// double time = 0;
	// double old_time = 0;
	// double moveSpeed;
	// double rotSpeed;
	t_ray	*ray;

	ray = data->game->ray;

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

	// while(1)
	// {
		i = 0;
		while (i < WIDTH)
		{
			cameraX = 2 * i / (double)WIDTH -1;
			ray->Dir.x = player->dir.x + player->plane.x * cameraX;
			ray->Dir.y = player->dir.y + player->plane.y * cameraX;
			//which box of the map we're in
			ray->mapX = (int)player->pos.x;
			ray->mapY = (int)player->pos.y;
			//length of ray from one x or y-side to next x or y-side
			if (ray->Dir.x == 0)
				ray->deltaDist.x = 1e30;
			else
				ray->deltaDist.x = fabs(1 / ray->Dir.x);
			if (ray->Dir.y == 0)
				ray->deltaDist.y = 1e30;
			else
				ray->deltaDist.y = fabs(1 / ray->Dir.y);

			//calculate step and initial sideDist
			if (ray->Dir.x < 0)
			{
				ray->stepX = -1;
				ray->sideDist.x = (player->pos.x - ray->mapX) * ray->deltaDist.x;
			}
			else
			{
				ray->stepX = 1;
				ray->sideDist.x = (ray->mapX + 1.0 - player->pos.x) * ray->deltaDist.x;
			}
			if (ray->Dir.y < 0)
			{
				ray->stepY = -1;
				ray->sideDist.y = (player->pos.y - ray->mapY) * ray->deltaDist.y;
			}
			else
			{
				ray->stepY = 1;
				ray->sideDist.y = (ray->mapY + 1.0 - player->pos.y) * ray->deltaDist.y;
			}
			//algo DDA
			ray->hit = 0 ;
			while (ray->hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
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
				//Check if ray has hit a wall
				if (map[ray->mapX][ray->mapY] > 0)
					ray->hit = 1;
			}
			if (ray->side == 0)
				ray->perpWallDist = (ray->sideDist.x - ray->deltaDist.x);
			else
				ray->perpWallDist = (ray->sideDist.y - ray->deltaDist.y);
			//Calculate height of line to draw on screen
			ray->lineHeight = (int)(HEIGHT / ray->perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			ray->drawStart = -ray->lineHeight / 2 + HEIGHT / 2;
			if (ray->drawStart < 0)
				ray->drawStart = 0;
			ray->drawEnd = ray->lineHeight / 2 + HEIGHT / 2;
			if (ray->drawEnd >= HEIGHT)
				ray->drawEnd = HEIGHT - 1;

			//choose wall color
			switch(map[ray->mapX][ray->mapY])
			{
				case 1:  color = 0xFF0000; break; //red
				case 2:  color = 0x00FF00; break; //green
				case 3:  color = 0x0000FF; break; //blue
				case 4:  color = 0xFFFFFF; break; //white
				default: color = 0xFFFF00; break; //yellow
			}

			//give x and y sides different brightness
			if (ray->side == 1) 
				color = color / 2;
			verLine(data, i, ray->drawStart, ray->drawEnd, color);
			i++;
		}
//	}
}