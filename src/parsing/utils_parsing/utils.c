/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_found.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:34:19 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/14 14:09:25 by yohurteb         ###   ########.fr       */
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
	if (line[0] == '\n')
		return (0);
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_strdup_double_array(t_data *data, char **s1)
{
	char	**cpy;
	int		j;

	j = 0;
	while (s1[j])
		j++;
	cpy = (char **)malloc(sizeof(char *) * (j + 1));
	if (!cpy)
		exit_clean(data, EXIT_FAILURE);
	j = 0;
	while (s1[j])
	{
		cpy[j] = ft_strdup(s1[j]);
		if (!cpy[j])
		{
			freetab(cpy);
			exit_clean(data, EXIT_FAILURE);
		}
		j++;
	}
	cpy[j] = NULL;
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
	if (c == '0' || c == '1' || c == '#')
		return (1);
	return (0);
}
