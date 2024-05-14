/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:40:31 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/14 11:42:28 by jbremser         ###   ########.fr       */
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


void	the_big_free(t_map *game)
{
	ft_printf("inside big free\n");
	// print_map(game);
	ft_printf("address of game->map:%p\n", game->map);
	free_array(game->map);
	// ft_printf("address of game->p_ani->animes:%p\n", game->p_ani->animes);
	// free_animes(game->mlx, game->p_ani->animes);
	ft_printf("address of game->p_ani->ids:%p\n", game->p_ani->ids);
	// free(game->p_ani);
	// free(game->map);
	ft_printf("address of game->copy:%p\n", game->copy);
	free(game->images);
	free(game->tokens_ani);
	ft_printf("address of game:%p\n", game);
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
	// ft_bzero(game, 0);
	// game->emote_time = 0;
	game->p_position.y = 0;
	game->p_position.x = 0;
	game->columns = 0;
	game->rows = 0;
	game->tokens = 0;
	game->exit = 0;
	game->player = 0;
	game->copy = NULL;
	game->cur_frame = 0;
	game->emote_time = 0;
	game->p_ani = NULL;
	game->token_index = 0;
	game->steps = -1;
	// game->p_ani->pos.x = 0;
	// game->p_ani->pos.y = 0;
}

	// free(game->copy); /* this is an extra free*/
	// ft_printf("address of game->images:%p\n", game->images);