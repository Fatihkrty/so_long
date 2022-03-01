/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:33:18 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/01 11:01:53 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	character_direction(t_mlx *mlx, int curr_x, int curr_y)
{
	mlx->char_move++;
	if (mlx->map[curr_x][curr_y] == 'E' && mlx->score == mlx->c_count)
	{
		ft_printf("Oyun Bitti..\nSkorunuz: %d\n", mlx->score);
		exit_app(mlx, NULL);
	}
	else if (mlx->map[curr_x][curr_y] != '1' && mlx->map[curr_x][curr_y] != 'E')
	{
		if (mlx->map[curr_x][curr_y] == 'C')
			mlx->score++;
		mlx->map[mlx->current_x][mlx->current_y] = '0';
		mlx->current_x = curr_x;
		mlx->current_y = curr_y;
		mlx->map[curr_x][curr_y] = 'P';
		mlx_clear_window(mlx->mlx, mlx->windows);
		render_map(mlx);
	}
}

void	move_character_left(t_mlx *mlx)
{
	mlx->curr_pos = 'L';
	character_direction(mlx, mlx->current_x, mlx->current_y - 1);
}

void	move_character_right(t_mlx *mlx)
{
	mlx->curr_pos = 'R';
	character_direction(mlx, mlx->current_x, mlx->current_y + 1);
}

void	move_character_up(t_mlx *mlx)
{
	mlx->curr_pos = 'U';
	character_direction(mlx, mlx->current_x - 1, mlx->current_y);
}

void	move_character_down(t_mlx *mlx)
{
	mlx->curr_pos = 'D';
	character_direction(mlx, mlx->current_x + 1, mlx->current_y);
}
