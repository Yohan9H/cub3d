/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_no_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:36:57 by yohurteb          #+#    #+#             */
/*   Updated: 2024/11/05 14:07:43 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	endl_become_zero_in_endmap(t_data *data, char **map)
{
	int		end;

	end = 0;
	while (map[end])
		end++;
	end -= 2;
	if (end == -1)
	{
		ft_fprintf("Error\nmiss map\n");
		exit_clean(data, EXIT_FAILURE);
	}
	while (map[end])
	{
		if (map[end][0] == '\n')
			map[end][0] = '\0';
		else
			break ;
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
			exit_clean(data, EXIT_FAILURE);
		}
		x++;
	}
}
