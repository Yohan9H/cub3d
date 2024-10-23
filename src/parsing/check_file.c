/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:52:45 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/23 12:12:58 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	svg_texture_in_img(t_data *data, char *id, char *line)
{
	if (ft_strncmp(id, "NO", 3) == 0)
	{
		data->game->textures[0]->path = ft_strdup(line);
		if (!data->game->textures[0]->path)
			exit_clean(data, EXIT_FAILURE);
	}
	else if (ft_strncmp(id, "SO", 3) == 0)
	{
		data->game->textures[1]->path = ft_strdup(line);
		if (!data->game->textures[1]->path)
			exit_clean(data, EXIT_FAILURE);
	}
	else if (ft_strncmp(id, "WE", 3) == 0)
	{
		data->game->textures[2]->path = ft_strdup(line);
		if (!data->game->textures[2]->path)
			exit_clean(data, EXIT_FAILURE);
	}
	else if (ft_strncmp(id, "EA", 3) == 0)
	{
		data->game->textures[3]->path = ft_strdup(line);
		if (!data->game->textures[3]->path)
			exit_clean(data, EXIT_FAILURE);
	}
}

void	svg_str_for_ray(t_data *data, char *line, char *id)
{
	char	*str;
	int		i;

	if (line == NULL)
		return ;
	i = skip_id(data, line);
	while (line[i] && ft_isspace(line[i]) == 1)
		i++;
	str = ft_strdup_esc(&line[i]);
	if (!str)
		exit_clean(data, EXIT_FAILURE);
	svg_texture_in_img(data, id, str);
	free(str);
}

void	take_line(t_data *data, char *id, char *line)
{
	if (line[0] == '\n')
		return ;
	if (ft_strncmp(id, "NO", 3) == 0)
	{
		svg_str_for_ray(data, line, id);
		data->pars->no = 1;
	}
	else if (ft_strncmp(id, "SO", 3) == 0)
	{
		svg_str_for_ray(data, line, id);
		data->pars->so = 1;
	}
	else if (ft_strncmp(id, "WE", 3) == 0)
	{
		svg_str_for_ray(data, line, id);
		data->pars->we = 1;
	}
	else if (ft_strncmp(id, "EA", 3) == 0)
	{
		svg_str_for_ray(data, line, id);
		data->pars->ea = 1;
	}
	else
		verif_id_colors(data, id, line);
}

void	take_id(t_data *data, char *line)
{
	int		i;

	i = 0;
	if (line == NULL || line[i] == '\n')
		return ;
	while (line[i] && ft_isalpha(line[i]) != 1)
		i++;
	if (data->pars->id != NULL)
		free(data->pars->id);
	data->pars->id = ft_strdup_esc(&line[i]);
	if (!data->pars->id)
		exit_clean(data, EXIT_FAILURE);
}

void	check_file(t_data *data)
{
	data->pars->line = get_next_line(data->pars->fd);
	if (data->pars->line != NULL)
	{
		take_id(data, data->pars->line);
		take_line(data, data->pars->id, data->pars->line);
	}
	while (data->pars->line != NULL && check_all_found(data, data->pars) != 1)
	{
		free(data->pars->line);
		data->pars->line = get_next_line(data->pars->fd);
		if (data->pars->line == NULL)
			break ;
		take_id(data, data->pars->line);
		take_line(data, data->pars->id, data->pars->line);
	}
	if (data->pars->line == NULL)
	{
		ft_fprintf("Error : miss value in your file\n");
		exit_clean(data, EXIT_FAILURE);
	}
}
