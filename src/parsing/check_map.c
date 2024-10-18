/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/17 17:44:45 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_close(t_data *data, char **tab, int y, int x)
{
	if (tab[y][x] == '#')
		return (0);
	tab[y][x] = '#';
	if (x == 0 || x == (int)ft_strlen(tab[y]) - 1 || y == 0
		|| y == data->pars->size_tab->y - 1)
		return (1);
// need fix tomorow
	if (one_or_zero(tab[y - 1][x]) || one_or_zero(tab[y + 1][x])
		|| one_or_zero(tab[y][x - 1]) || one_or_zero(tab[y][x + 1]))
		return (1);
	if (tab[y - 1][x] == '0')
		return (verif_close(data, tab, y - 1, x));
	if (tab[y + 1][x] == '0')
		return (verif_close(data, tab, y + 1, x));
	if (tab[y][x - 1] == '0')
		return (verif_close(data, tab, y, x - 1));
	if (tab[y][x + 1] == '0')
		return (verif_close(data, tab, y, x + 1));
	tab[y][x] = '0';
	return (0);
}

void	check_close(t_data *data, char **tab)
{
	int		y;
	int		x;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x++])
		{
			if (tab[y][x] == '0')
				if (verif_close(data, tab, y, x) == 1)
				{
					ft_fprintf("Error : map not close\n");
					freetab(tab);
					exit_clean(data, EXIT_FAILURE);
				}
			x++;
		}
		y++;
	}
}

void	take_value_and_verif(t_data *data, char c, int j, int i)
{
	if (c == 'N')
	{
		(data->pars->no)++;
		data->pars->begin_ply->y = j;
		data->pars->begin_ply->x = i;
	}
	if (c == 'S')
	{
		(data->pars->so)++;
		data->pars->begin_ply->y = j;
		data->pars->begin_ply->x = i;
	}
	if (c == 'E')
	{
		(data->pars->ea)++;
		data->pars->begin_ply->y = j;
		data->pars->begin_ply->x = i;
	}
	if (c == 'W')
	{
		(data->pars->we)++;
		data->pars->begin_ply->y = j;
		data->pars->begin_ply->x = i;
	}
	if ((data->pars->no + data->pars->so + data->pars->we + data->pars->ea) \
		> 1)
	{
		ft_fprintf("Error : too many N, S, E or W in your map\n");
		exit_clean(data, EXIT_FAILURE);
	}
	if (c == ' ')
		c = 1;
}

void	reset_value_map(t_data *data)
{
	data->pars->no = 0;
	data->pars->so = 0;
	data->pars->we = 0;
	data->pars->ea = 0;
}

void	verif_good_map(t_data *data)
{
	char	**cpy_map;
	int		y;
	int		x;

	y = 0;
	reset_value_map(data);
	while (data->game->map[y])
	{
		x = 0;
		while (data->game->map[y][x])
		{
			take_value_and_verif(data, data->game->map[y][x], y, x);
			x++;
		}
		y++;
	}
	cpy_map = ft_strdup_double_array(data, data->game->map);
	check_close(data, cpy_map);
	freetab(cpy_map);
}
