/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:36:04 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/27 16:34:26 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_map *game;

	if (argc != 2)
	{
		ft_putstr_fd("Arg Count Wrong\n", 2);
		return (1);
	}
	game = malloc(sizeof(t_map));
	if (!game)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else
	{
		struct_zero(game);
		map_init(game, argv[1]);
		// add_mlx(game, mlx);
	}
	the_big_free(game);
	return (0);
}
