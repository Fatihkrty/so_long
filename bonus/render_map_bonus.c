/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:38:17 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/04 12:52:12 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_character(t_mlx *mlx, int x, int y)
{
	mlx->char_move++;
	if (mlx->curr_pos == 'R')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_char_right, x, y);
	else if (mlx->curr_pos == 'L')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_char_left, x, y);
	else if (mlx->curr_pos == 'U')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_char_up, x, y);
	else if (mlx->curr_pos == 'D')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_char_down, x, y);
}

void	write_score(t_mlx *mlx)
{
	char	*score;
	char	*move;

	score = ft_itoa(mlx->score);
	move = ft_itoa(mlx->char_move);
	mlx_string_put(mlx->mlx, mlx->windows, 30, 30, 0xffffff, "Score: ");
	mlx_string_put(mlx->mlx, mlx->windows, 100, 30, 0xffffff, score);
	mlx_string_put(mlx->mlx, mlx->windows, 30, 50, 0xffffff, "Hareket: ");
	mlx_string_put(mlx->mlx, mlx->windows, 100, 50, 0xffffff, move);
	free(score);
	free(move);
}

void	put_image(t_mlx *mlx, int i, int j)
{
	if (mlx->map[i][j] == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_wall, mlx->x, mlx->y);
	else if (mlx->map[i][j] == 'P')
		render_character(mlx, mlx->x, mlx->y);
	else if (mlx->map[i][j] == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_heart, mlx->x, mlx->y);
	else if (mlx->map[i][j] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->windows, \
		mlx->create_girl, mlx->x, mlx->y);
}

void	render_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->x = 0;
	mlx->y = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			put_image(mlx, i, j);
			mlx->x += 64;
			j++;
		}
		if (mlx->map[i][j] == 0)
			mlx->x = 0;
		mlx->y += 64;
		i++;
	}
	write_score(mlx);
}
