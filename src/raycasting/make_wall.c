/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:48:14 by apernot           #+#    #+#             */
/*   Updated: 2024/10/28 11:29:57 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

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
			my_pixel_put(data, i, j, get_color(data->pars->c_rvb));
		else if (j > data->game->ray->dred)
			my_pixel_put(data, i, j, get_color(data->pars->f_rvb));
		j++;
	}
}
