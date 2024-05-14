/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:55:47 by jbremser          #+#    #+#             */
/*   Updated: 2024/05/13 17:05:38 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int anime_picker(t_map *game, int y, int x, t_ani *ani)
{
	int i = 0;
	mlx_image_t *img;
	int id;

	ft_printf("inside anime_picker: ani->len:%i\n", ani->len);
	ani->pos.y = y;
	ani->pos.x = x;
	while (i < ani->len)
	{
		img = ani->animes[i];
		if (img)
			id = mlx_image_to_window(game->mlx,
					ani->animes[i], x * PIXELS, y * PIXELS);
		else
			return (0);
		ani->ids[i] = id;
		img->instances[id].enabled = false;
		i++;
	}
	ani->enabled = true;
	return (1);
}
static void tokens_picker(t_map *game, int y, int x)
{
	if (game->tokens_ani)
		ft_printf("%p\n", game->tokens_ani);
	if (game->token_index)
		ft_printf("%i\n", game->token_index);
	// ft_printf("%p, %i, %i\n", game->tokens_ani, y, x);
	if (anime_picker(game, y, x, game->tokens_ani[game->token_index++]) == 0)
				ft_putstr_fd("C:Animes failed", 2);
	ft_printf("%p, %i, %i\n", game, y, x);
}

static void image_picker(t_map *game, int y, int x)
{
	if (game->map[y][x]  == '1')
	{
		if (mlx_image_to_window(game->mlx,
				game->images->wall, x * PIXELS, y * PIXELS) < 0)
			error_exit_array("Error: image: wall\n", game, game->map);
	}
	if (game->map[y][x]  == 'E')
	{
		if (mlx_image_to_window(game->mlx,
				game->images->exit_closed, x * PIXELS, y * PIXELS) < 0)
			error_exit_array("Error: image: closed exit\n", game, game->map);
	}
	if (game->map[y][x]  == 'P')
		if (anime_picker(game, y, x, game->p_ani) == 0)
				ft_putstr_fd("P:Animes failed", 2);
}

/* 37 to 46 should be in own function */
static void floorfill(t_map *game)
{
	int x;
	int y;
	
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (mlx_image_to_window(game->mlx, game->images->floor, x * PIXELS, y * PIXELS) < 0)
				error_exit_array("Error: floorfill\n", game, game->map);
			x++;
		}
		y++;
	}
}
static void	wall_exit_add(t_map *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'E' || game->map[y][x] == '1')
				image_picker(game, y, x);
			x++;
		}
		y++;
	}
}

static void player_tokens_add(t_map *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
				image_picker(game, y, x);
			else if (game->map[y][x] == 'C')		
				tokens_picker(game, y, x);
			x++;
		}
		y++;
	}
}


void map_render(t_map *game)
{
	floorfill(game);
	wall_exit_add(game);
	player_tokens_add(game);
}
	// ft_printf("\nplayer position:[%d][%d]\n", game->p_position.y, game->p_position.x);
	// ft_printf("\nexit position:[%d][%d]\n", game->e_position.y, game->e_position.x);
	// print_map(game);
		// if (mlx_image_to_window(game->mlx, game->images->player, x * PIXELS, y * PIXELS) < 0)
		// 	error_exit_array("Error: image: player\n", game, game->map);
		// ft_printf("\nbefore Anime picker!\n");