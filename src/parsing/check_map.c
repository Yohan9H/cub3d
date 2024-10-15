/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:41:22 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/15 15:20:12 by apernot          ###   ########.fr       */
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

// char	**my_env_to_tab(t_map *env)
// {
// 	t_env	*lst;
// 	char	**tab;
// 	size_t	size;
// 	int		i;

// 	lst = env;
// 	size = ft_lstsize_env(env);
// 	tab = (char **)malloc(sizeof(char *) * (size + 1));
// 	if (!tab)
// 		return (NULL);
// 	i = 0;
// 	while (lst)
// 	{
// 		tab[i] = ft_strdup(lst->line);
// 		if (!tab[i])
// 		{
// 			freetab(tab);
// 			return (NULL);
// 		}
// 		i++;
// 		lst = lst->next;
// 	}
// 	tab[i] = NULL;
// 	return (tab);
// }

void	create_linked_list_map(t_data *data)
{
	(void)data;
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
