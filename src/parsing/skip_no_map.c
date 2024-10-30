/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_no_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:36:57 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/30 14:36:33 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_endl(t_data *data, char **map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		if (map[x][0] == '\n')
			x++;
		else
		{
			data->pars->skip_endl = x;
			break ;
		}
		data->pars->skip_endl = x;
	}
}

void	endl_become_zero_in_endmap(t_data *data, char **map)
{
	int		end;

	end = 0;
	while (map[end])
		end++;
	end--;
	while (map[end] && end > data->pars->skip_endl)
	{
		if (map[end][0] == '\n')
			map[end][0] = '\0';
		else
			return ;
		end--;
	}
	data->pars->end_map = end;
}

void	verif_endl_in_map(t_data *data, char **map)
{
	int		x;

	x = 0;
	while (map[x])
	{
		if (map[x][0] == '\n')
		{
			ft_fprintf("Error\nnew line in map\n");
			freetab(map);
			exit_clean(data, EXIT_FAILURE);
		}
		x++;
	}
}
