/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:19:10 by fkaratay          #+#    #+#             */
/*   Updated: 2022/03/04 14:44:44 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_file_len(t_mlx *mlx, char *str)
{
	int		fd;
	int		i;
	char	c;
	char	*ber;

	i = 0;
	while (str[i])
		i++;
	str += i - 4;
	ber = ".ber";
	while (*str)
		if (*str++ != *ber++)
			exit_app(mlx, "Dosya Uzantisi Hatasi..\n", 1);
	str -= i + 8;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit_app(mlx, "Dosya Acma Hatasi..\n", 1);
	i = 0;
	while (read(fd, &c, 1))
		i++;
	close(fd);
	return (i);
}

void	control_newline(t_mlx *mlx, char *map)
{
	int	new_line;
	int	i;

	new_line = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			new_line++;
		i++;
	}
	i = 0;
	while (mlx->map[i])
		i++;
	if (i - 1 != new_line)
	{
		free(map);
		exit_app(mlx, "Haritada fazla new line mevcut..\n", 1);
	}
}

void	read_maps(t_mlx *mlx, char *str)
{
	int		fd;
	int		file_len;
	int		i;
	char	*map;

	file_len = ft_file_len(mlx, str);
	fd = open(str, O_RDONLY);
	map = malloc(sizeof(char) * file_len + 1);
	if (!map)
		exit_app(mlx, "Malloc alan ayirma hatasi..\n", 1);
	i = read(fd, map, file_len);
	map[i] = '\0';
	close(fd);
	mlx->map = ft_split(map, '\n');
	control_newline(mlx, map);
	free(map);
	control_maps(mlx);
}
