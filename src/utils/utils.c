/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:44:57 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/09 11:27:29 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pixel_index(int x, int y, int line_bytes, int pixel_bits)
{
	int	pixel_index;

	pixel_index = y * line_bytes + x * (pixel_bits / 8);
	return (pixel_index);
}

void	put_pxl(t_data *fcl, int x, int y, int color)
{
	char	*dst;

	dst = fcl->addr + pixel_index(x, y, fcl->line_bytes, fcl->pixel_bits);
	*(unsigned int *)dst = color;
}

void	exit_clean(t_data *fcl, int code)
{
	if (fcl->img)
		mlx_destroy_image(fcl->mlx, fcl->img);
	if (fcl->mlx_win)
		mlx_destroy_window(fcl->mlx, fcl->mlx_win);
	if (fcl->mlx)
	{
		mlx_destroy_display(fcl->mlx);
		free(fcl->mlx);
	}
	if (code == EXIT_FAILURE)
		exit(1);
	if (code == EXIT_SUCCESS)
		exit(0);
}
