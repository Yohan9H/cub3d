/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/11/05 14:42:17 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	verif_close(t_data *data, char **tab, int x, int y)
{
	if (tab[x][y] == '#')
		return (0);
	tab[x][y] = '#';
	if (y == 0 || y == (int)ft_strlen(tab[x]) - 1 || x == 0
		|| x == data->pars->size_tab->x - 1)
		return (1);
	if (check_char(tab[x - 1][y]) != 1 || check_char(tab[x + 1][y]) != 1
		|| check_char(tab[x][y - 1]) != 1 || check_char(tab[x][y + 1]) != 1)
		return (1);
	if (tab[x - 1][y] == '0')
		return (verif_close(data, tab, x - 1, y));
	if (tab[x + 1][y] == '0')
		return (verif_close(data, tab, x + 1, y));
	if (tab[x][y - 1] == '0')
		return (verif_close(data, tab, x, y - 1));
	if (tab[x][y + 1] == '0')
		return (verif_close(data, tab, x, y + 1));
	tab[x][y] = '0';
	return (0);
}

void	check_close(t_data *data, char **tab)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == '0')
			{
				if (verif_close(data, tab, x, y) == 1)
				{
					ft_fprintf("Error\nbad map\n");
					exit_clean(data, EXIT_FAILURE);
				}
			}
			y++;
		}
		x++;
	}
}

int	take_value_and_verif(t_data *data, char c, int x, int y)
{
	int		res;

	check_if_player(data, c, x, y);
	res = (data->pars->no + data->pars->so + data->pars->we + data->pars->ea);
	if (res > 1)
	{
		ft_fprintf("Error\ntoo many N, S, E or W OR char no accepted\n");
		exit_clean(data, EXIT_FAILURE);
	}
	if (c == ' ')
		c = 1;
	return (res);
}

void	verif_player(t_data *data, char **map)
{
	int		res;
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			res = take_value_and_verif(data, map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (res == 0)
	{
		ft_fprintf("Error\nmiss N, S, E or W\n");
		exit_clean(data, EXIT_FAILURE);
	}
}

void	verif_good_map(t_data *data)
{
	reset_value_map(data);
	verif_player(data, data->game->map);
	del_pos_player(data, data->game->map);
	check_if_char_no_accept(data, data->game->map);
	endl_become_zero_in_endmap(data, data->game->map);
	verif_endl_in_map(data, data->game->map);
	check_close(data, data->game->map);
}
