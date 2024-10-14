/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:20:14 by apernot           #+#    #+#             */
/*   Updated: 2024/10/14 18:59:35 by apernot          ###   ########.fr       */
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

int	handle_keys(int keycode, t_data *data, t_player *player)
{
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
		player->pos.x = player->pos.x + player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y + player->plane.y * MOVE_SPEED;
	}
	else if (keycode == BACK)
	{
		player->pos.x = player->pos.x - player->plane.x * MOVE_SPEED;
		player->pos.y = player->pos.y - player->plane.y * MOVE_SPEED;
	}
	else if (keycode == ROT_LEFT)
	{
		player->dir.x = player->dir.x * cos(-ROT_SPEED) - player->dir.y * sin(-ROT_SPEED);
		player->plane.x = player->plane.x * cos(-ROT_SPEED) - player->plane.y * sin(-ROT_SPEED);
		player->dir.y = player->dir.x * sin(-ROT_SPEED) + player->dir.y * cos(-ROT_SPEED);
		player->plane.y = player->plane.x * sin(-ROT_SPEED) + player->plane.y * cos(-ROT_SPEED);
	}
	else if (keycode == ROT_RIGHT)
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
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int	stepX;
	int	stepY;
	int hit;
	int side;
	int	lineHeight;
	int drawStart;
	int drawEnd;
	int	color;
	double time = 0;
	double old_time = 0;
	double moveSpeed;
	double rotSpeed;

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
			rayDirX = player->dir.x + player->plane.x * cameraX;
			rayDirY = player->dir.y + player->plane.y * cameraX;
			//which box of the map we're in
			mapX = (int)player->pos.x;
			mapY = (int)player->pos.y;
			//length of ray from one x or y-side to next x or y-side
			if (rayDirX == 0)
				deltaDistX = 1e30;
			else
				deltaDistX = fabs(1 / rayDirX);
			if (rayDirY == 0)
				deltaDistY = 1e30;
			else
				deltaDistY = fabs(1 / rayDirY);

			//calculate step and initial sideDist
			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (player->pos.x - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - player->pos.x) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (player->pos.y - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - player->pos.y) * deltaDistY;
			}
			//algo DDA
			hit =0 ;
			while (hit == 0)
			{
				//jump to next map square, either in x-direction, or in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (map[mapX][mapY] > 0)
					hit = 1;
			}
			if (side == 0)
				perpWallDist = (sideDistX - deltaDistX);
			else
				perpWallDist = (sideDistY - deltaDistY);
			//Calculate height of line to draw on screen
			lineHeight = (int)(HEIGHT / perpWallDist);

			//calculate lowest and highest pixel to fill in current stripe
			drawStart = -lineHeight / 2 + HEIGHT / 2;
			if (drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + HEIGHT / 2;
			if (drawEnd >= HEIGHT)
				drawEnd = HEIGHT - 1;

			//choose wall color
			switch(map[mapX][mapY])
			{
				case 1:  color = 0xFF0000; break; //red
				case 2:  color = 0x00FF00; break; //green
				case 3:  color = 0x0000FF; break; //blue
				case 4:  color = 0xFFFFFF; break; //white
				default: color = 0xFFFF00; break; //yellow
			}

			//give x and y sides different brightness
			if (side == 1) 
				color = color / 2;
			verLine(data, i, drawStart, drawEnd, color);
			i++;
		}
		old_time = time;
		moveSpeed = 
//	}
}