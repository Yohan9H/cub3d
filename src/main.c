/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:02:40 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 16:32:20 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

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
	data->addr = mlx_get_data_addr(data->img, &pixel_bits,
		&line_bytes, &endian);
	data->pixel_bits = pixel_bits;
	data->line_bytes = line_bytes;


	data->game = malloc(sizeof(t_game));
	if (!data->game)
		exit_clean(data, EXIT_FAILURE);
	data->game->map = malloc(sizeof(t_map));
	data->game->player = malloc(sizeof(t_player));
	data->game->ray = malloc(sizeof(t_ray));
	
}

int	main(int ac, char **av)
{
	t_data	data;

	ac--;
	(void)av;
	parsing(&data, ac, av);
	init_struct(&data);
	game(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keys, &data);
	mlx_hook(data.mlx_win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	exit_clean(&data, EXIT_SUCCESS);
}
