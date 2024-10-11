/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:27:33 by apernot           #+#    #+#             */
/*   Updated: 2024/10/11 15:41:54 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "cub3d.h"

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}				t_player;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	delta_dist;
	double		dist;
	int			map_x;
	int			map_y;
}				t_ray;

typedef struct s_map
{
	int		witdh;
	int		height;
	int		**grid;
}			t_map;

#endif