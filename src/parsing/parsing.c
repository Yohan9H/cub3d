/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:50:35 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/22 15:29:04 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	data->game->textures[0]->addr = NULL;
	data->game->textures[0]->img = NULL;
	data->game->textures[0]->path = NULL;
	data->game->textures[1]->addr = NULL;
	data->game->textures[1]->img = NULL;
	data->game->textures[1]->path = NULL;
	data->game->textures[2]->addr = NULL;
	data->game->textures[2]->img = NULL;
	data->game->textures[2]->path = NULL;
	data->game->textures[3]->addr = NULL;
	data->game->textures[3]->img = NULL;
	data->game->textures[3]->path = NULL;
}

void	init_data(t_data *data)
{
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		exit_clean(data, EXIT_FAILURE);
	data->game->map = NULL;
	data->game->player = malloc(sizeof(t_player));
	data->game->ray = malloc(sizeof(t_ray));
	for (int i = 0; i < 4; i++)
		data->game->textures[i] = malloc(sizeof(t_img));
	init_textures(data);
	data->addr = NULL;
	data->img = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->pars = (t_pars *)malloc(sizeof(t_pars) * 1);
	if (!data->pars)
		exit_clean(data, EXIT_FAILURE);
	ft_memset(data->pars, 0, sizeof(t_pars));
	data->pars->fd = -1;
	reset_value_map(data);
	data->pars->begin_ply = (t_point *)malloc(sizeof(t_point) * 1);
	if (!data->pars->begin_ply)
		exit_clean(data, EXIT_FAILURE);
	data->pars->begin_ply->y = 0;
	data->pars->begin_ply->x = 0;
	data->pars->size_tab = (t_point *)malloc(sizeof(t_point) * 1);
	if (!data->pars->size_tab)
		exit_clean(data, EXIT_FAILURE);
	data->pars->size_tab->x = 0;
	data->pars->size_tab->y = 0;
	data->pars->c_rvb = (t_rvb *)malloc(sizeof(t_rvb) * 1);
	if (!data->pars->c_rvb)
		exit_clean(data, EXIT_FAILURE);
	data->pars->c_rvb->r = 120;
	data->pars->c_rvb->v = 200;
	data->pars->c_rvb->b = 255;
	data->pars->f_rvb = (t_rvb *)malloc(sizeof(t_rvb) * 1);
	if (!data->pars->f_rvb)
		exit_clean(data, EXIT_FAILURE);
	data->pars->f_rvb->r = 12;
	data->pars->f_rvb->v = 80;
	data->pars->f_rvb->b = 70;
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
	check_file(data); // voir si ./path_to_the_....._texture doit etre verifier si il n'existe pas
	check_map(data);
}
