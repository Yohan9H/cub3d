/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:50:35 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 15:21:37 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parsing(t_data *data)
{
	data->addr = NULL;
	data->img = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->pars = (t_pars *)malloc(sizeof(t_pars) * 1);
	if (!data->pars)
		exit_clean(data, EXIT_FAILURE);
	data->pars->line = NULL;
	data->pars->no = 0;
	data->pars->so = 0;
	data->pars->we = 0;
	data->pars->ea = 0;
	data->pars->f = 0;
	data->pars->c = 0;
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
	check_args(data, ac, av[1]);
	check_file(data, av[1]);
}
