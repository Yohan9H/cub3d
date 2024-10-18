/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:50:35 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/18 12:05:33 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_data *data)
{
	data->game = (t_game *)malloc(sizeof(t_game) * 1); // a changer plus tard
	data->game->map = NULL;
	data->game->player = malloc(sizeof(t_player));
	data->game->ray = malloc(sizeof(t_ray));
	data->addr = NULL;
	data->img = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->pars = (t_pars *)malloc(sizeof(t_pars) * 1);
	if (!data->pars)
		exit_clean(data, EXIT_FAILURE);
	ft_memset(data->pars, 0, sizeof(t_pars));
	data->pars->begin_ply = (t_point *)malloc(sizeof(t_point) * 1);
	if (!data->pars->begin_ply)
		exit_clean(data, EXIT_FAILURE);
	data->pars->begin_ply->y = 0;
	data->pars->begin_ply->x = 0;
	data->pars->size_tab = (t_point *)malloc(sizeof(t_point) * 1);
	if (!data->pars->size_tab)
		exit_clean(data, EXIT_FAILURE);
	ft_memset(data->pars->size_tab, 0, sizeof(t_point));
}

void	check_args(t_data *data, int ac, char *file)
{
	int		i;

	i = 0;
	if (ac >= 2 || ac == 0)
	{
		ft_fprintf("Error : you need only one args (./filename.cub)\n");
		exit_clean(data, EXIT_FAILURE);
	}
	while (file[i] && file[i] != '.')
		i++;
	if (file[i] != '.')
	{
		ft_fprintf("Error : your file is not valide (./filename.cub)\n");
		exit_clean(data, EXIT_FAILURE);
	}
	i++;
	while (file[i] && file[i] != '.')
		i++;
	if (ft_strncmp(&file[i], ".cub", 5) != 0)
	{
		ft_fprintf("Error : your file is not valide (./filename.cub)\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	parsing(t_data *data, int ac, char **av)
{
	init_parsing(data);
	check_args(data, ac, av[1]); // need handle "EA       ./name"
	check_file(data, av[1]); // voir si ./path_to_the_....._texture doit etre verifier si il n'existe pas
	check_map(data);
}
