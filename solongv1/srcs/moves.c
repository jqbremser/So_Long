/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:04:00 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/14 11:44:31 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_ani_pos(t_ani *ani)
{
	int	i;

	i = 0;
	if (ani == NULL)
		return ;

	while (i < ani->len)
	{
		ani->animes[i]->instances[ani->ids[i]].x = ani->pos.x * PIXELS;
		ani->animes[i]->instances[ani->ids[i]].y = ani->pos.y * PIXELS;
		i++;
	}
}


void	move_up(t_map *game)
{
	if (game->p_ani == NULL)
		return ;
	if (game->map[game->p_ani->pos.y - 1][game->p_ani->pos.x] != '1')
	{
		if (game->map[game->p_ani->pos.y - 1][game->p_ani->pos.x] == 'C')
		{
			remove_token(game, game->p_ani->pos.y - 1, game->p_ani->pos.x);
			game->map[game->p_ani->pos.y - 1][game->p_ani->pos.x] = '0';
		}
		if (game->map[game->p_ani->pos.y - 1][game->p_ani->pos.x] == 'E')
		{
			time_to_exit(game);
		}
		game->p_ani->pos.y -= 1;
		update_ani_pos(game->p_ani);
		step_counter_init(game);
		ft_printf("\nSteps: %i\n", game->steps);
	}
}

void	move_down(t_map *game)
{
	if (game->p_ani == NULL)
		return ;
	if (game->map[game->p_ani->pos.y + 1][game->p_ani->pos.x] != '1')
	{
		if (game->map[game->p_ani->pos.y + 1][game->p_ani->pos.x] == 'C')
		{
			remove_token(game, game->p_ani->pos.y + 1, game->p_ani->pos.x);
			game->map[game->p_ani->pos.y + 1][game->p_ani->pos.x] = '0';
		}
		if (game->map[game->p_ani->pos.y + 1][game->p_ani->pos.x] == 'E')
		{
			time_to_exit(game);
		}
		game->p_ani->pos.y += 1;
		update_ani_pos(game->p_ani);
		step_counter_init(game);
		ft_printf("\nSteps: %i\n", game->steps);
	}
}

void	move_left(t_map *game)
{
	if (game->p_ani == NULL)
		return ;
	if (game->map[game->p_ani->pos.y][game->p_ani->pos.x - 1] != '1')
	{
		if (game->map[game->p_ani->pos.y][game->p_ani->pos.x - 1] == 'C')
		{
			remove_token(game, game->p_ani->pos.y, game->p_ani->pos.x - 1);
			game->map[game->p_ani->pos.y][game->p_ani->pos.x - 1] = '0';
		}
		if (game->map[game->p_ani->pos.y][game->p_ani->pos.x - 1] == 'E')
		{
			time_to_exit(game);
		}
		game->p_ani->pos.x -= 1;
		update_ani_pos(game->p_ani);
		step_counter_init(game);
		ft_printf("\nSteps: %i\n", game->steps);
	}
}

void move_right(t_map *game)
{
	if (game->p_ani == NULL)
		return ;
	if (game->map[game->p_ani->pos.y][game->p_ani->pos.x + 1] != '1')
	{
		if (game->map[game->p_ani->pos.y][game->p_ani->pos.x + 1] == 'C')
		{
			remove_token(game, game->p_ani->pos.y, game->p_ani->pos.x + 1);
			game->map[game->p_ani->pos.y][game->p_ani->pos.x + 1] = '0';
		}
		if (game->map[game->p_ani->pos.y][game->p_ani->pos.x + 1] == 'E')
		{
			time_to_exit(game);
		}
		game->p_ani->pos.x += 1;
		update_ani_pos(game->p_ani);
		step_counter_init(game);
		ft_printf("\nSteps: %i\n", game->steps);
	}
}

void    step_counter_init(t_map *game)
{
    char    *s;
	char	*temp;

	game->steps += 1;
    s = ft_itoa(game->steps);
	if (!s)
		return ;
	temp = ft_strjoin("Steps:", s);	
    mlx_delete_image(game->mlx, game->step_counter);
    game->step_counter = mlx_put_string(game->mlx, temp, game->rows * PIXELS / 2, 8);
    free(s);
	free(temp);
}


// void emote(void *param)
// {
// 	t_map *game = param;
// 	int	loops = 0;

// 	while (loops < 4)
// 	{
// 		game->emote_time += game->mlx->delta_time;
// 		if (game->emote_time > 1)
// 		{
// 			if (loops == 0)
// 			{
// 				game->p_position.x += 1;
// 				game->images->player->instances[0].x += 1 * PIXELS;
// 			}
// 			else if (loops == 1)
// 			{
// 				game->p_position.y -= 1;
// 				game->images->player->instances[0].y -= 1 * PIXELS;
// 			}
// 			else if (loops == 2)
// 			{
// 				game->p_position.y += 1;
// 				game->images->player->instances[0].y += 1 * PIXELS;
// 			}
// 			else if (loops == 3)
// 			{
// 				game->p_position.x -= 1;
// 				game->images->player->instances[0].x -= 1 * PIXELS;
// 			}
// 			ft_printf("\nloop increase\n");
// 			game->emote_time = 0;
// 			loops++;
// 		}
// 	}
// }


	// game->p_position.y += 1;
	// game->images->player->instances[0].y += 1 * PIXELS;
	// game->p_position.x -= 1;
	// game->images->player->instances[0].x -= 1 * PIXELS;
// void emote(t_map *game)
// {
// 	game->p_position.x += 1;
// 	game->images->player->instances[0].x += 1 * PIXELS;
// 	game->p_position.y -= 1;
// 	game->images->player->instances[0].y -= 1 * PIXELS;
// 	game->p_position.y += 1;
// 	game->images->player->instances[0].y += 1 * PIXELS;
// 	game->p_position.x -= 1;
// 	game->images->player->instances[0].x -= 1 * PIXELS;
// }
