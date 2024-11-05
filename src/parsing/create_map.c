/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/11/05 12:24:56 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	take_lenght_max(t_data *data, t_map *lst)
{
	int		len_str;

	while (lst && lst->line != NULL)
	{
		len_str = ft_strlen(lst->line);
		if (data->pars->size_tab->y < len_str)
			data->pars->size_tab->y = len_str;
		lst = lst->next;
	}
}

void	init_create(t_data *data, size_t *size, t_map **lst)
{
	while (*lst && (*lst)->line && (*lst)->line[0] == '\n')
		*lst = (*lst)->next;
	*size = ft_lstsize(*lst);
	data->pars->size_tab->x = *size - 1;
	data->game->map = (char **)malloc(sizeof(char *) * (*size + 1));
	if (!data->game->map)
		exit_clean(data, EXIT_FAILURE);
}

void	create_double_array(t_data *data)
{
	t_map	*lst;
	size_t	size;
	int		i;
	int		y_lgt;

	lst = data->pars->head_map;
	init_create(data, &size, &lst);
	i = 0;
	take_lenght_max(data, lst);
	y_lgt = data->pars->size_tab->y;
	while (lst && lst->line != NULL)
	{
		data->game->map[i] = ft_calloc(y_lgt + 1, sizeof(char));
		if (!data->game->map[i])
			exit_clean(data, EXIT_FAILURE);
		ft_memcpy(data->game->map[i], lst->line, ft_strlen(lst->line));
		i++;
		lst = lst->next;
	}
	data->game->map[i++] = ft_calloc(data->pars->size_tab->y + 1, sizeof(char));
	data->game->map[i] = NULL;
}

void	create_linked_list_map(t_data *data)
{
	t_map	*node;

	while (data->pars->line != NULL)
	{
		node = ft_lstnew(data->pars->line);
		ft_lstadd_back(&data->pars->head_map, node);
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
	}
	node = ft_lstnew(NULL);
	ft_lstadd_back(&data->pars->head_map, node);
}

void	check_map(t_data *data)
{
	create_linked_list_map(data);
	create_double_array(data);
	verif_good_map(data);
	all_space_become_one(data, data->game->map);
}
