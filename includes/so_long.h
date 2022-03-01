/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkaratay <fkaratay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:19:26 by fkaratay          #+#    #+#             */
/*   Updated: 2022/02/25 16:33:00 by fkaratay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BONUS
#  define BONUS 0
# endif

enum {
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	ESC_KEY = 53
};

typedef struct s_data {
	int		img_height;
	int		img_weight;

	void	*windows;
	void	*mlx;

	void	*create_wall;
	void	*create_char_up;
	void	*create_char_down;
	void	*create_char_right;
	void	*create_char_left;
	void	*create_heart;
	void	*create_girl;

	int		p_count;
	int		e_count;
	int		c_count;

	char	**map;

	int		row_len;
	int		column_len;

	int		current_x;
	int		current_y;
	int		x;
	int		y;
	int		score;
	int		char_move;
	char	curr_pos;
}				t_mlx;

char	**ft_split(char const *str, char c);
void	read_maps(t_mlx *mlx, char *str);
void	move_character_down(t_mlx *mlx);
void	move_character_up(t_mlx *mlx);
void	move_character_right(t_mlx *mlx);
void	move_character_left(t_mlx *mlx);
void	control_maps(t_mlx *mlx);
void	render_map(t_mlx *mlx);
void	ft_printf(const char *str, ...);
int		exit_app(t_mlx *mlx, char *str);
void	configure_settings(t_mlx *mlx);
char	*ft_itoa(int n);
void	create_img(t_mlx *mlx);

#endif
