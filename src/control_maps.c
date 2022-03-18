/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:26:28 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/04 13:00:50 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	control_len(t_mlx *mlx, char *str)
{
	static int	row_len = 0;
	int			i;

	i = 0;
	if (row_len == 0)
		while (str[i++])
			row_len++;
	i = 0;
	while (str[i])
		i++;
	if (i != row_len)
		exit_app(mlx, "Satir uzunluklari farkli..", 1);
}

void	control_end_line(t_mlx *mlx, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			exit_app(mlx, "Son satirda duvar eksik..", 1);
		i++;
	}
}

void	count_elements(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->current_x = i;
				mlx->current_y = j;
				mlx->p_count++;
			}
			else if (mlx->map[i][j] == 'C')
				mlx->c_count++;
			else if (mlx->map[i][j] == 'E')
				mlx->e_count++;
			j++;
		}
		i++;
	}
	if (mlx->p_count != 1 || mlx->e_count < 1 || mlx->c_count < 1)
		exit_app(mlx, "Yeterli sayıda eleman yok..", 1);
}

void	control_elements(t_mlx *mlx, char c)
{
	if (!('P' == c || 'C' == c || '1' == c || '0' == c || 'E' == c))
		exit_app(mlx, "Yasak elementler var..", 1);
}

void	control_maps(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (i == 0 && mlx->map[0][j] != '1')
				exit_app(mlx, "1. satirda duvar eksik..", 1);
			control_elements(mlx, mlx->map[i][j]);
			j++;
		}
		if (mlx->map[i][0] != '1')
			exit_app(mlx, "Sol satirlarda duvar eksik..", 1);
		if (mlx->map[i][j - 1] != '1')
			exit_app(mlx, "Sag satirlarda duvar eksik..", 1);
		control_len(mlx, mlx->map[i]);
		i++;
	}
	count_elements(mlx);
	control_end_line(mlx, mlx->map[i - 1]);
}
