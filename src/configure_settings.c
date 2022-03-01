/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:22:14 by fkaratay          #+#    #+#             */
/*   Updated: 2022/02/25 14:31:12 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_img(t_mlx *mlx)
{
	mlx->create_char_up = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/character/char_up.xpm", &mlx->img_weight, &mlx->img_height);
	mlx->create_char_down = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/character/char_down.xpm", &mlx->img_weight, &mlx->img_height);
	mlx->create_char_left = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/character/char_left.xpm", &mlx->img_weight, &mlx->img_height);
	mlx->create_char_right = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/character/char_right.xpm", &mlx->img_weight, &mlx->img_height);
	mlx->create_wall = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/elements/wall_64x64.xpm", &mlx->img_weight, &mlx->img_height);
	mlx->create_heart = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/elements/heart_64x64.xpm", &mlx->img_weight, &mlx->img_height);
	mlx->create_girl = mlx_xpm_file_to_image(mlx->mlx, \
	"./assets/elements/girl.xpm", &mlx->img_weight, &mlx->img_height);
}

void	configure_settings(t_mlx *mlx)
{
	int		i;

	i = 0;
	create_img(mlx);
	while (mlx->map[i++])
		mlx->row_len++;
	i = 0;
	while (mlx->map[0][i++])
		mlx->column_len++;
	mlx->windows = mlx_new_window(mlx->mlx, (mlx->column_len) * 64, \
	(mlx->row_len) * 64, "So_Long");
	render_map(mlx);
}
