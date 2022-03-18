/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:24:31 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/04 14:40:36 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	key_event(int key, t_mlx *mlx)
{
	if (key == ESC_KEY)
	{
		ft_printf("Cikis Yaptiniz..\n");
		exit_app(mlx, NULL, 0);
	}
	else if (key == W_KEY)
		move_character_up(mlx);
	else if (key == A_KEY)
		move_character_left(mlx);
	else if (key == S_KEY)
		move_character_down(mlx);
	else if (key == D_KEY)
		move_character_right(mlx);
	return (0);
}

void	app_defines_null(t_mlx *mlx)
{
	mlx->map = NULL;
	mlx->mlx = NULL;
	mlx->create_heart = NULL;
	mlx->create_girl = NULL;
	mlx->create_wall = NULL;
	mlx->create_char_down = NULL;
	mlx->create_char_left = NULL;
	mlx->create_char_right = NULL;
	mlx->create_char_up = NULL;
}

void	app_defines(t_mlx *mlx)
{
	mlx->current_x = 0;
	mlx->current_y = 0;
	mlx->score = 0;
	mlx->char_move = -1;
	mlx->row_len = 0;
	mlx->column_len = 0;
	mlx->c_count = 0;
	mlx->p_count = 0;
	mlx->e_count = 0;
	mlx->curr_pos = 'R';
	app_defines_null(mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc == 2)
	{
		mlx = malloc(sizeof(t_mlx));
		if (!mlx)
			return (1);
		app_defines(mlx);
		read_maps(mlx, argv[1]);
		mlx->mlx = mlx_init();
		configure_settings(mlx);
		mlx_hook(mlx->windows, 2, 1L << 0, key_event, mlx);
		mlx_hook(mlx->windows, 17, 1L << 17, exit_app, mlx);
		mlx_loop(mlx->mlx);
	}
	else
		ft_printf("Yetersiz arguman..");
	return (0);
}
