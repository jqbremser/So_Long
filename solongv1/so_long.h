/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:46:56 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/26 16:36:23 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>

typedef	struct s_position
{
	int y;
	int x;
} t_position;

typedef struct s_map
{
	char 		**map;
	char 		**copy;
	int			columns; //y;
	int 		rows;	//x;
	int 		tokens;
	int			exit;
	int 		player;
	t_position 	p_position;
	t_position 	e_position;
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
void	free_array(char **);
void	print_map(t_map *game);//remove before submit
void	print_copy(t_map *game);//remove before submit
size_t	ft_strlen_delim(char *str, char delim);
void	struct_zero(t_map	*game);
void	the_big_free(t_map *game);


#endif // SO_LONG_H
