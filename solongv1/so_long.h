/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:46:56 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/14 11:36:53 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

# define PIXELS 64	

typedef	struct s_position
{
	int y;
	int x;
} t_position;

typedef struct s_img
{
	mlx_image_t	*wall;
	// mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*token;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
}	t_img;

typedef struct s_ani
{
	t_position 	pos;
	// mlx_image_t	*image;
	mlx_image_t	**animes;
	int			*ids;
	int			len;
	int			enabled;
	int			loop;
} t_ani;

typedef struct s_map
{
	char 		**map;
	char 		**copy;
	int			columns; //y;
	int 		rows;	//x;
	int 		tokens;
	int			exit;
	int 		player;
	int			steps;
	int			collected;
	t_position 	p_position;
	t_position 	e_position;
	mlx_t		*mlx;
	t_img		*images;
	t_ani		*p_ani;
	t_ani		**tokens_ani;
	t_ani		*e_ani;
	double		emote_time;
	bool		can_i_emote;
	int			cur_frame;
	int			token_index;
	mlx_image_t	*step_counter;
} t_map;

/* ************************************************************************** */
/*                                   so_long								  */
/* ************************************************************************** */
int		main(int argc, char **argv);

/* ************************************************************************** */
/*                                   map_init								  */
/* ************************************************************************** */
int		map_init(t_map *game, char *args);
char	**map_to_str(t_map *game, char *args);

/* ************************************************************************** */
/*                                   error_time								  */
/* ************************************************************************** */
void	freenull(char **ptr);
int 	error_msg_exit(char *msg, t_map *game);
void error_exit_array(char *msg, t_map	*game, char **array);
void	free_array(char **str);
void free_animes(mlx_t *mlx, t_ani *ani);


/* ************************************************************************** */
/*                                   map_parse								  */
/* ************************************************************************** */
int 	map_parse(t_map *game);
int 	edge_me_baby(t_map *game, int i, int j);
int 	char_check(t_map *game, int i, int j);
void 	set_positions(t_map *game, int i, int j);
int 	count_check(t_map *game, int j);

/* ************************************************************************** */
/*                                   fill									  */
/* ************************************************************************** */
char	**map_copy(t_map *game);
int floodfill(t_map	*game);
void fill(t_map	*game, int y, int x);
int check_copy(t_map *game);

/* ************************************************************************** */
/*                                   utils									  */
/* ************************************************************************** */
void	print_map(t_map *game);//remove before submit
void	print_copy(t_map *game);//remove before submit
size_t	ft_strlen_delim(char *str, char delim);
void	struct_zero(t_map	*game);
void	the_big_free(t_map *game);

/* ************************************************************************** */
/*                                   mlx									  */
/* ************************************************************************** */
void mlx_starter(t_map *game);
t_img *images_init(t_map *game);

/* ************************************************************************** */
/*                                   map_render								  */
/* ************************************************************************** */
void map_render(t_map *game);

/* ************************************************************************** */
/*                                   assets									  */
/* ************************************************************************** */
void load_wall_asset(t_map *game, t_img *img);
void load_token_asset(t_map *game, t_img *img);
void load_player_asset(t_map *game, t_img *img);
void load_floor_asset(t_map *game, t_img *img);
void load_exit_o_asset(t_map *game, t_img *img);
void load_exit_c_asset(t_map *game, t_img *img);

/* ************************************************************************** */
/*                                   moves									  */
/* ************************************************************************** */
void	move_up(t_map *game);
void	move_down(t_map *game);
void	move_left(t_map *game);
void	move_right(t_map *game);
void    step_counter_init(t_map *game);

// void	emote(void *param);

/* ************************************************************************** */
/*                                   token									  */
/* ************************************************************************** */
void	remove_token(t_map	*game, int y, int x);
void	time_to_exit(t_map	*game);


/* ************************************************************************** */
/*                                   animations								  */
/* ************************************************************************** */
void    animation_loop(void *param);
t_ani	*p_animes_init(t_map *game);
t_ani	*t_animes_init(t_map *game);
t_ani	*e_animes_init(t_map *game);

void	animate(t_map *game, t_ani *ani);



#endif // SO_LONG_H
