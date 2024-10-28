/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:03:38 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/28 11:52:44 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "enum.h"
# include "parsing.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "X11/X.h"
# include "X11/keysym.h"
# include "ray.h"
# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_game	t_game;

typedef	struct s_state
{
	int front;
	int	back;
	int right;
	int left;
	int	rot_l;
	int rot_r;
	int	esc;
}		t_state;

typedef struct s_data
{
	t_pars	*pars;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		line_bytes;
	int		pixel_bits;
	t_state	*key_states;
	t_game	*game;
}			t_data;

//	---- GAME ----
void	game(t_data *data);

//	---- HOOK ----
int		handle_key(int keycode, t_data *data);

int		handle_close(t_data *data);

//	---- UTILS ----
void	put_pxl(t_data *fcl, int x, int y, int color);

void	exit_clean(t_data *data, int code);

#endif