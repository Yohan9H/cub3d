/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/16 19:00:39 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_double_array(t_data *data)
{
	t_map	*lst;
	size_t	size;
	int		len_str;
	int		i;

	lst = data->pars->head_map;
	size = ft_lstsize(lst);
	data->pars->size_tab->y = size - 1;
	data->game->map = (char **)malloc(sizeof(char *) * size);
	if (!data->game->map)
		exit_clean(data, EXIT_FAILURE);
	i = 0;
	while (lst->line != NULL)
	{
		data->game->map[i] = ft_strdup(lst->line);
		if (!data->game->map[i])
			exit_clean(data, EXIT_FAILURE);
		len_str = ft_strlen(data->game->map[i]);
		if (data->pars->size_tab->x < len_str)
			data->pars->size_tab->x = len_str - 1;
		i++;
		lst = lst->next;
	}
	data->game->map[i] = NULL;
}

void	create_linked_list_map(t_data *data)
{
	t_map *node;
	int		len_lst;

	node = ft_lstnew(data->pars->line);
	ft_lstadd_back(&data->pars->head_map, node);
	while (data->pars->line != NULL)
	{
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
		node = ft_lstnew(data->pars->line);
		ft_lstadd_back(&data->pars->head_map, node);
	}
	len_lst = ft_lstsize(data->pars->head_map);
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
	create_double_array(data);
	verif_good_map(data);
}
