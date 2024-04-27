/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:16:35 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/27 16:42:02 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_copy(t_map *game)
{
	int y;

	y = 0;
	game->copy = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->copy)
	{
		ft_putstr_fd("Error:malloc\n", 2);
		free_array(game->copy);
	}
	while (game->map[y])
	{
		game->copy[y] = ft_strdup(game->map[y]);
		y++;
	}
	game->copy[y] = NULL;
	return (game->copy);
}

int		floodfill(t_map	*game)
{
	game->copy = map_copy(game);
	if (!game->copy)
		return (0);
	ft_printf("\nplayer position:[%d][%d]\n", game->p_position.y, game->p_position.x);
	print_copy(game);
	fill(game, game->p_position.y, game->p_position.x);
	if (check_copy(game) == 0)
	{
		free_array(game->copy);
		free(game->copy);
		return (0);
	}
	ft_printf("\nplayer position:[%d][%d]\n", game->p_position.y, game->p_position.x);
	print_copy(game);
	free_array(game->copy);
	return (1);
}
int check_copy(t_map *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (game->copy[y])
	{
		while (game->copy[y][x])
		{
			if (game->copy[y][x] == 'E' || game->copy[y][x] == 'C' || game->copy[y][x] == 'P')
			{	
				print_copy(game);
				return (0);
			}
			x++;	
		}
		x = 0;
		y++;
	}
	return (1);
}


void fill(t_map	*game, int y, int x)
{
	if (game->copy[y][x] == '1' || game->copy[y][x] == 'F')
		return ;
	else
		game->copy[y][x] = 'F';
	fill(game, y + 1, x);
	fill(game, y - 1, x);
	fill(game, y, x + 1);
	fill(game, y, x - 1);
}