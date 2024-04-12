/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:36:04 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/11 16:46:12 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
	argv[1] = "maps/map.ber";
	argc = 2;
	t_map *game;
	
	game = malloc(sizeof(t_map));
	if (!game || argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
		map_init(game, argv[1]);
	return (0);
}
 