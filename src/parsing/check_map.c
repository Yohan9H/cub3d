/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/16 18:54:40 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill(char **tab, t_point *size, t_point *cur, char to_fill)
{
	if (cur->x < 0 || cur->x >= size->x || cur->y < 0 || cur->y >= size->y || tab[cur->y][cur->x] != to_fill)
		return ;
	tab[cur->y][cur->x] = 'F';
	fill(tab, size, &((t_point){cur->x - 1, cur->y}), to_fill);
	fill(tab, size, &((t_point){cur->x + 1, cur->y}), to_fill);
	fill(tab, size, &((t_point){cur->x, cur->y - 1}), to_fill);
	fill(tab, size, &((t_point){cur->x, cur->y + 1}), to_fill);
}

void	flood_fill(char **tab, t_point *size, t_point *begin)
{
	fill(tab, size, begin, tab[begin->y][begin->x]);
}

void	take_value_and_verif(t_data *data, char c, int j, int i)
{
	if (c == 'N')
	{
		(data->pars->no)++;
		data->pars->begin->y = j;
		data->pars->begin->x = i;
	}
	if (c == 'S')
	{
		(data->pars->so)++;
		data->pars->begin->y = j;
		data->pars->begin->x = i;
	}
	if (c == 'E')
	{
		(data->pars->ea)++;
		data->pars->begin->y = j;
		data->pars->begin->x = i;
	}
	if (c == 'W')
	{
		(data->pars->we)++;
		data->pars->begin->y = j;
		data->pars->begin->x = i;
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
	int		j;
	int		i;

	j = 0;
	reset_value_map(data);
	while (data->game->map[j])
	{
		i = 0;
		while (data->game->map[j][i])
		{
			take_value_and_verif(data, data->game->map[j][i], j, i);
			i++;
		}
		j++;
	}
	cpy_map = ft_strdup_double_array(data, data->game->map);
	flood_fill(cpy_map, data->pars->size_tab, data->pars->begin);
	freetab(cpy_map);
}
