/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:50:35 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/24 11:41:36 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data_two(t_data *data)
{
	data->key_states = (t_state *)ft_calloc(1, sizeof(t_state));
	if (!data->key_states)
		exit_clean(data, EXIT_FAILURE);
}

void	init_data(t_data *data)
{
	data->game = ft_calloc(1, sizeof(t_game));
	if (!data->game)
		exit_clean(data, EXIT_FAILURE);
	data->game->player = ft_calloc(1, sizeof(t_player));
	data->game->ray = ft_calloc(1, sizeof(t_ray));
	for (int i = 0; i < 4; i++)
		data->game->textures[i] = ft_calloc(1, sizeof(t_img));
	data->game->begin_ply = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!data->game->begin_ply)
		exit_clean(data, EXIT_FAILURE);
	data->pars = (t_pars *)ft_calloc(1, sizeof(t_pars));
	if (!data->pars)
		exit_clean(data, EXIT_FAILURE);
	data->pars->fd = -1;
	data->pars->size_tab = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!data->pars->size_tab)
		exit_clean(data, EXIT_FAILURE);
	data->pars->c_rvb = (t_rvb *)ft_calloc(1, sizeof(t_rvb));
	if (!data->pars->c_rvb)
		exit_clean(data, EXIT_FAILURE);
	data->pars->f_rvb = (t_rvb *)ft_calloc(1, sizeof(t_rvb));
	if (!data->pars->f_rvb)
		exit_clean(data, EXIT_FAILURE);
	init_data_two(data);
}

void	check_args(t_data *data, int ac, char *file)
{
	int		i;

	i = 0;
	if (ac >= 2 || ac == 0)
	{
		ft_fprintf("Error : you need only one args (filename.cub)\n");
		exit_clean(data, EXIT_FAILURE);
	}
	data->pars->fd = open(file, O_RDONLY);
	if (data->pars->fd == -1)
	{
		ft_fprintf("Error : file not found\n");
		exit_clean(data, EXIT_FAILURE);
	}
	if (file[i] && file[i] == '.')
		i++;
	while (file[i] && file[i] != '.')
		i++;
	if (ft_strncmp(&file[i], ".cub", 5) != 0)
	{
		ft_fprintf("Error : your file is not valide (filename.cub)\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	parsing(t_data *data, int ac, char **av)
{
	init_data(data);
	check_args(data, ac, av[1]);
	check_file(data);
	check_map(data);
}
