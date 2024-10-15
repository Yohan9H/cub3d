/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:27:33 by apernot           #+#    #+#             */
/*   Updated: 2024/10/15 11:48:49 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# define FRONT 119
# define BACK 115
# define LEFT 97
# define RIGHT 100
# define ROT_LEFT 65361
# define ROT_RIGHT 65363
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# include "cub3d.h"

typedef struct s_data	t_data;

typedef struct s_game
{
	t_player	*player;
	t_ray		*ray;
	t_map		*map;
}				t_game;

typedef struct s_vector
{
	double	x;
	double	y;
}			t_vector;

typedef struct s_player
{
	t_vector	*pos;
	t_vector	*dir;
	t_vector	*plane;
}				t_player;

typedef struct s_ray
{
	t_vector	*dir;
	t_vector	*delta_dist;
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

typedef struct s_color
{
    int r;
    int g;
    int b;
} 		t_color;

void	raycasting(t_data *data, t_player *player);
void	handle_keys(int keycode, t_data *img, t_player *player);

#endif