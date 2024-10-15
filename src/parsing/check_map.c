/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 11:45:13 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	found_map(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

void	create_linked_list_map(t_data *data)
{
	t_map *node;

	node = ft_lstnew(data->pars->line);
	ft_lstadd_back(&data->pars->head_map, node);
	while (data->pars->line != NULL)
	{
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
		node = ft_lstnew(data->pars->line);
		ft_lstadd_back(&data->pars->head_map, node);
	}
}

void	check_map(t_data *data)
{
	
	while (data->pars->line != NULL && found_map(data->pars->line) != 1)
	{
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
	}
	if (data->pars->line == NULL)
	{
		ft_fprintf("Error : map not found in your file\n");
		exit_clean(data, EXIT_FAILURE);
	}
	create_linked_list_map(data);
}
