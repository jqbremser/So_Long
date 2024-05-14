/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:20:56 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/08 12:38:22 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int edge_me_baby(t_map *game, int i, int j)
// {
// 	while (game->map[0])
// 	{
// 		if (game->map[0][i] == '1')
// 			i++;
// 		else if (game->map[0][i] == '\n')
// 			break ;
// 		else
// 			return (0);
// 	}
// 	i = 0;
// 	j = 1;
// 	while (j < (game->rows - 1))
// 	{
// 		if (game->map[j][0] != '1' || game->map[j][game->columns - 1] != '1')
// 			return (0);
// 		j++;
// 	}
// 	while (game->map[game->rows - 1])
// 	{
// 		if (game->map[game->rows - 1][i] == '1')
// 			i++;
// 		else if (game->map[0][i] == '\n')
// 			break ;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

void	set_positions(t_map *game, int i, int j)
{
	if (game->map[j][i] == 'P')
	{
		game->p_position.y = j;
		game->p_position.x = i;
		game->player++;
	}
	else if (game->map[j][i] == 'E')
	{
		game->e_position.y = j;
		game->e_position.x = i;
		game->exit++;
	}
	else if (game->map[j][i] == 'C')
		game->tokens++;
}

int	char_check(t_map *game, int i, int j)
{
	while (j < game->rows)
	{
		while (game->map[j][i])
		{
			if (game->map[j][i] == '1' || game->map[j][i] == '0'
			|| game->map[j][i] == 'P' || game->map[j][i] == 'E'
			|| game->map[j][i] == 'C' || game->map[j][i] == '\n')
			{
				set_positions(game, i, j);
				i++;
			}
			else
				return (0);
		}
		i = 0;
		j++;
	}
	return (1);
}

int	count_check(t_map *game, int j)
{
	size_t length;

	j = 0;
	length = ft_strlen_delim(game->map[0], '\n');
	if (game->player != 1 || game->exit != 1 || game->tokens < 1)
		return (0);
	while (game->map[j])
	{
		if (ft_strlen_delim(game->map[j], '\n') != length)
			return (0);
		j++;
	}
	return (1);
}


	// ft_printf("player position:[%d][%d]\n", game->p_position.y, game->p_position.x);
	// ft_printf("exit position:[%d][%d]\n", game->e_position.y, game->e_position.x);
	// ft_printf("columns: %d\n", game->columns);


int edge_me_baby(t_map *game, int i, int j)
{
	while (j < game->rows)
	{
		while (i < game->columns)
		{
			if ((j == 0 || j == (game->rows - 1)) && game->map[j][i] != '1')
				return (0);
			if ((j > 0 && j < (game->rows - 1)) && (game->map[j][0] != '1'
				|| game->map[j][game->columns - 1] != '1'))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	map_parse(t_map *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (edge_me_baby(game, i, j) == 0 || char_check(game, i, j) == 0
		|| count_check(game, j) == 0 || floodfill(game) == 0)
		return (0);
	return (1);
}