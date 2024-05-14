/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:01:30 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/13 17:26:05 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_exit(t_map	*game, t_position e_pos)
{
	if (mlx_image_to_window(game->mlx, game->images->exit_open, e_pos.x * PIXELS, e_pos.y * PIXELS) < 0)
			error_exit_array("Error: image: closed exit\n", game, game->map);
}

void	time_to_exit(t_map	*game)
{
	if (game->collected >= game->tokens)
	{
		ft_printf("You win!");
		mlx_close_window(game->mlx);
	}
}

void	remove_token(t_map	*game, int y, int x)
{
	int	i;
	int j;
	t_ani *temp;
	
	i = 0;
	game->collected++;
	while (i < game->tokens)
	{
		temp = game->tokens_ani[i];
		if (temp->pos.x == x && temp->pos.y == y)
		{
			j = 0;
			while (j < temp->len)
			{
				temp->animes[j]->instances[temp->ids[j]].enabled = false;
				j++;
			}
			temp->enabled = false;
			ft_printf("collectible collected");
		}
		i++;
	}
	if (game->collected >= game->tokens)
		update_exit(game, game->e_position);
}

