/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:40:31 by jbremser          #+#    #+#             */
/*   Updated: 2024/04/27 17:01:03 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_copy(t_map *game)//remove before submit
{
	int	i = 0;
	ft_printf("\nMap copy is:\n");
	while (game->copy[i] != '\0')
	{
		ft_printf("%s", game->copy[i]);
		i++;
	}
}

void	print_map(t_map *game)//remove before submit
{
	int	i = 0;
	ft_printf("\nMap is:\n");
	while (game->map[i] != '\0')
	{
		ft_printf("%s", game->map[i]);
		i++;
	}
}

void free_array(char **str)
{
	int y;

	y = 0;
	while (str[y])
		free(str[y++]);
	// free(str);
}

void	the_big_free(t_map *game)
{
	print_map(game);
	free_array(game->map);
	free(game->map);
	free(game->copy);
	free(game);
}

size_t	ft_strlen_delim(char *str, char delim)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] && str[count] != delim)
		count++;
	return (count);
}

void	struct_zero(t_map	*game)
{
	game->columns = 0;
	game->rows = 0;
	game->tokens = 0;
	game->exit = 0;
	game->player = 0;
	game->copy = NULL;
}
