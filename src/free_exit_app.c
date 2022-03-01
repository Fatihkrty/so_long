/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:05:52 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/01 11:17:08 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	exit_app(t_mlx *mlx, char *str)
{
	if (str)
		ft_printf("ERROR\n%s", str);
	if (mlx->create_wall)
		mlx_destroy_image(mlx->mlx, mlx->create_wall);
	if (mlx->create_heart)
		mlx_destroy_image(mlx->mlx, mlx->create_heart);
	if (mlx->create_girl)
		mlx_destroy_image(mlx->mlx, mlx->create_girl);
	if (mlx->create_char_down)
		mlx_destroy_image(mlx->mlx, mlx->create_char_down);
	if (mlx->create_char_left)
		mlx_destroy_image(mlx->mlx, mlx->create_char_left);
	if (mlx->create_char_right)
		mlx_destroy_image(mlx->mlx, mlx->create_char_right);
	if (mlx->create_char_up)
		mlx_destroy_image(mlx->mlx, mlx->create_char_up);
	if (mlx->map)
		free_map(mlx->map);
	if (mlx)
		free(mlx);
	exit(1);
}
