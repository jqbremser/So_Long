/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:36:04 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/17 14:54:02 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

 void print_map(t_map *game)//remove before submit
{
	int	i = 0;
	ft_printf("Map is:\n");
	while (game->map[i] != '\0')
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_map *game;

	game = malloc(sizeof(t_map));
	if (!game || argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else
		map_init(game, argv[1]);
	print_map(game);
	return (0);
}