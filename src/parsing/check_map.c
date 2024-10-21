/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/21 15:36:17 by yohurteb         ###   ########.fr       */
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
	if (check_char(tab[y - 1][x]) != 1 || check_char(tab[y + 1][x]) != 1
		|| check_char(tab[y][x - 1]) != 1 || check_char(tab[y][x + 1]) != 1)
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
		while (tab[y][x])
		{
			if (tab[y][x] == '0')
				if (verif_close(data, tab, y, x) == 1)
				{
					ft_fprintf("Error : bad map\n");
					freetab(tab);
					exit_clean(data, EXIT_FAILURE);
				}
			x++;
		}
		y++;
	}
}

int	take_value_and_verif(t_data *data, char c, int y, int x)
{
	int		res;

	check_if_palyer(data, c, y, x);
	res = (data->pars->no + data->pars->so + data->pars->we + data->pars->ea);
	if (res > 1)
	{
		ft_fprintf("Error : too many N, S, E or W in your map\n");
		exit_clean(data, EXIT_FAILURE);
	}
	if (c == ' ')
		c = 1;
	return (res);
}

void	verif_player(t_data *data, char **map)
{
	int		res;
	int		y;
	int		x;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			res = take_value_and_verif(data, map[y][x], y, x);
			x++;
		}
		y++;
	}
	if (res == 0)
	{
		ft_fprintf("Error : miss N, S, E or W in your map\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	verif_good_map(t_data *data)
{
	char	**cpy_map;

	reset_value_map(data);
	verif_player(data, data->game->map);
	del_pos_player(data->game->map);
	cpy_map = ft_strdup_double_array(data, data->game->map);
	print_data(data);
	check_close(data, cpy_map);
	freetab(cpy_map);
}
