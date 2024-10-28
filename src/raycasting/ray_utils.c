/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:02 by apernot           #+#    #+#             */
/*   Updated: 2024/10/28 11:30:00 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	hook_put(t_data *data, t_player *player)
{
	if (!data)
		return ;
	raycasting(data, player);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
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
