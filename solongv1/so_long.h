/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:46:56 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/17 15:32:06 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char **map;
	int	columns; //y;
	int rows;	//x;
	int tokens;
	int	exit;
	int player;
} t_map;

/* ************************************************************************** */
/*                                   so_long								  */
/* ************************************************************************** */
int main(int argc, char **argv);
void print_map(t_map *game);//remove before submit

/* ************************************************************************** */
/*                                   map_init								  */
/* ************************************************************************** */
int		map_init(t_map *game, char *args);
char	**map_to_str(t_map *game, char *args);

/* ************************************************************************** */
/*                                   error_time								  */
/* ************************************************************************** */
void	freenull(char **ptr);
int error_msg_exit(char *msg, t_map *game);


#endif // SO_LONG_H
