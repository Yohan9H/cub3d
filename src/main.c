/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:02:40 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/28 10:56:03 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_set(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
}

void	init_struct(t_data *data)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	data->mlx = mlx_init();
	if (!data->mlx)
		exit_clean(data, EXIT_FAILURE);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (!data->mlx_win)
		exit_clean(data, EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		exit_clean(data, EXIT_FAILURE);
	data->addr = mlx_get_data_addr(data->img, \
		&pixel_bits, &line_bytes, &endian);
	data->pixel_bits = pixel_bits;
	data->line_bytes = line_bytes;
}

int	main(int ac, char **av)
{
	t_data	data;

	ac--;
	mlx_set(&data);
	parsing(&data, ac, av);
	init_struct(&data);
	game(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, handle_keytoogle, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, handle_keytoogle, &data);
	mlx_loop_hook(data.mlx, &handle_keys, &data);
	mlx_hook(data.mlx_win, DestroyNotify, 0, handle_close, &data);
	mlx_loop(data.mlx);
	exit_clean(&data, EXIT_SUCCESS);
}
