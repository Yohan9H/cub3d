/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:03:38 by yohurteb          #+#    #+#             */
/*   Updated: 2024/10/10 11:48:59 by yohurteb         ###   ########.fr       */
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
# include "../mlx/mlx.h"
# define WIDTH 900
# define HEIGHT 900

typedef struct s_data
{
	t_pars	*pars;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		line_bytes;
	int		pixel_bits;
}	t_data;

//	---- GAME ----
void	game(t_data *data);

//	---- HOOK ----
int		handle_key(int keycode, t_data *fcl);

int		handle_close(t_data *fcl);

//	---- UTILS ----
void	put_pxl(t_data *fcl, int x, int y, int color);

void	exit_clean(t_data *data, int code);

#endif