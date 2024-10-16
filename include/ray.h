/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:27:33 by apernot           #+#    #+#             */
/*   Updated: 2024/10/15 16:44:59 by yohurteb         ###   ########.fr       */
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
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# include "cub3d.h"

typedef struct s_data	t_data;

typedef struct s_game
{
	t_player	*player;
	t_ray		*ray;
	char		**map;
}				t_game;

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
	t_vector	Dir;
	t_vector	sideDist;
	t_vector	deltaDist;
	double		perpWallDist;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int 		drawEnd;
}				t_ray;

typedef struct s_game
{
	t_player	*player;
	t_ray		*ray;
	int			**map;
}				t_game;







// typedef struct s_map
// {
// 	int		witdh;
// 	int		height;
// 	int		**grid;
// }			t_map;

typedef struct s_color
{
    int r;
    int g;
    int b;
} 		t_color;

void	raycasting(t_data *data, t_player *player);
int		handle_keys(int keycode, t_data *data);

#endif