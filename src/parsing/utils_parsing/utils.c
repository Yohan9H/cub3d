/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/11/07 11:40:19 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freetab(char **com)
{
	int	i;

	i = 0;
	while (com[i])
	{
		free(com[i]);
		i++;
	}
	free(com);
}

int	found_map(char *line)
{
	int		i;

	i = 0;
	if (line[0] != '\n')
		return (1);
	return (0);
}

int	is_player(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game->dir = NO;
		return (1);
	}
	if (c == 'S')
	{
		data->game->dir = SO;
		return (1);
	}
	if (c == 'W')
	{
		data->game->dir = WE;
		return (1);
	}
	if (c == 'E')
	{
		data->game->dir = EA;
		return (1);
	}
	return (0);
}

int	check_char(char c)
{
	if (c == '0' || c == '1' || c == '#')
		return (1);
	return (0);
}
