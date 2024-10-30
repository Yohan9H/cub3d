/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/30 14:51:46 by yohurteb         ###   ########.fr       */
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

char	**ft_strdup_double_array(t_data *data, char **s1)
{
	char	**cpy;
	int		x;
	int		x_cpy;

	cpy = malloc_ptr(data, data->pars->skip_endl);
	x = data->pars->skip_endl;
	x_cpy = 0;
	while (s1[x])
	{
		cpy[x_cpy] = ft_strdup(s1[x]);
		if (!cpy[x_cpy])
		{
			freetab(cpy);
			exit_clean(data, EXIT_FAILURE);
		}
		x_cpy++;
		x++;
	}
	cpy[x_cpy] = NULL;
	return (cpy);
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
	if (c == '0' || c == '1' || c == '#' || c == '\0')
		return (1);
	return (0);
}
